#include "ping.h"

Ping::Ping()
{
    m_maxPacketSize = 4;
    m_datalen = 56;
    m_nsend = 0;
    m_nreceived = 0;
    m_icmp_seq = 0;
}

unsigned short Ping::getChksum(unsigned short *addr,int len)
{   
    int nleft=len;
    int sum=0;
    unsigned short *w=addr;
    unsigned short answer=0;

    while(nleft>1)
    {
            sum+=*w++;
            nleft-=2;
    }

    if( nleft==1)
    {
            *(unsigned char *)(&answer)=*(unsigned char *)w;
            sum+=answer;
    }
    sum=(sum>>16)+(sum&0xffff);
    sum+=(sum>>16);
    answer=~sum;
    return answer;
}

int Ping::packIcmp(int pack_no, struct icmp* icmp)
{   
    int packsize;
    struct icmp *picmp;
    struct timeval *tval;

    picmp = icmp;
    picmp->icmp_type=ICMP_ECHO;
    picmp->icmp_code=0;
    picmp->icmp_cksum=0;
    picmp->icmp_seq=pack_no;
    picmp->icmp_id= m_pid;
    packsize= 8 + m_datalen;
    tval= (struct timeval *)icmp->icmp_data;
    gettimeofday(tval,NULL);
    picmp->icmp_cksum=getChksum((unsigned short *)icmp,packsize);
    return packsize;
}

bool Ping::unpackIcmp(char *buf,int len, struct IcmpEchoReply *icmpEchoReply)
{   
    int iphdrlen;
    struct ip *ip;
    struct icmp *icmp;
    struct timeval *tvsend, tvrecv, tvresult;
    double rtt;

    ip = (struct ip *)buf;
    iphdrlen = ip->ip_hl << 2;
    icmp = (struct icmp *)(buf + iphdrlen);
    len -= iphdrlen;
    if(len < 8)
    {
            printf("ICMP packets\'s length is less than 8\n");
            return false;
    }

    if( (icmp->icmp_type==ICMP_ECHOREPLY) && (icmp->icmp_id == m_pid) )
    {

            tvsend=(struct timeval *)icmp->icmp_data;
            gettimeofday(&tvrecv,NULL);
            tvresult = tvSub(tvrecv, *tvsend);
            rtt=tvresult.tv_sec*1000 + tvresult.tv_usec/1000;
            icmpEchoReply->rtt = rtt;
            icmpEchoReply->icmpSeq = icmp->icmp_seq;
            icmpEchoReply->ipTtl = ip->ip_ttl;
            icmpEchoReply->icmpLen = len;
            return true;
    }
    else {
            return false;
    }
}

struct timeval Ping::tvSub(struct timeval timeval1,struct timeval timeval2)
{ 	
    struct timeval result;
    result = timeval1;
    if ((result.tv_usec < timeval2.tv_usec) &&  (timeval2.tv_usec< 0))
    {
            --result.tv_sec;
            result.tv_usec += 1000000;
    }
    result.tv_sec -= timeval2.tv_sec;
    return result;
}

bool Ping::sendPacket()
{   
    size_t packetsize;
    while( m_nsend < m_maxPacketSize)
    {
        m_nsend++;
        m_icmp_seq++;
        packetsize = packIcmp(m_icmp_seq, (struct icmp*)m_sendpacket);

        if(sendto(m_sockfd,m_sendpacket, packetsize, 0, (struct sockaddr *) &m_dest_addr, sizeof(m_dest_addr)) < 0  )
        {
            perror("sendto error");
            continue;
        }
    }
    return true;
}

bool Ping::recvPacket(PingResult &pingResult)
{       
    int len = 0;
    extern int errno;
    struct IcmpEchoReply icmpEchoReply;
    int maxfds = m_sockfd + 1;
    int nfd  = 0;
    fd_set rset;
    FD_ZERO(&rset);
    socklen_t fromlen = sizeof(m_from_addr);
    struct timeval timeout;
    timeout.tv_sec = 4;
    timeout.tv_usec = 0;

    for (int recvCount = 0; recvCount < m_maxPacketSize; recvCount++)
    {
        //printf("begin recv\n");
        FD_SET(m_sockfd, &rset);
        if ((nfd = select(maxfds, &rset, NULL, NULL, &timeout)) == -1) {
                perror("select error");
                continue;
        }
        if (nfd == 0) {
                //recv time out
                //printf("request timeout\n");
                icmpEchoReply.isReply = false;
                pingResult.icmpEchoReplys.push_back(icmpEchoReply);
                continue;
        }
        if (FD_ISSET(m_sockfd, &rset)) {
                if( (len = recvfrom(m_sockfd, m_recvpacket,sizeof(m_recvpacket),0, (struct sockaddr *)&m_from_addr,&fromlen)) <0)
                {
                        if(errno==EINTR)
                                continue;
                        perror("recvfrom error");
                        continue;
                }
                icmpEchoReply.fromAddr = inet_ntoa(m_from_addr.sin_addr) ;
                if (icmpEchoReply.fromAddr != pingResult.ip) {
                        //printf("invalid address, discard\n");
                        //retry again
                        recvCount--;
                        continue;
                }
        }
        if(unpackIcmp(m_recvpacket, len, &icmpEchoReply)==-1) {
                //retry again
                recvCount--;
                continue;
        }
        icmpEchoReply.isReply = true;
        pingResult.icmpEchoReplys.push_back(icmpEchoReply);
        m_nreceived++;
    }
    return true;
}

bool Ping::getsockaddr(const char * hostOrIp, struct sockaddr_in* sockaddr) {
	struct hostent *host;
	struct sockaddr_in dest_addr;
	unsigned long inaddr=0l;
	bzero(&dest_addr,sizeof(dest_addr));
	dest_addr.sin_family=AF_INET;

    if( (inaddr=inet_addr(hostOrIp))==INADDR_NONE)
	{    
		if((host=gethostbyname(hostOrIp))==NULL) /*是主机名*/
		{   
			//printf("gethostbyname error:%s\n", hostOrIp);
			return false;
		}
		memcpy( (char *)&dest_addr.sin_addr,host->h_addr,host->h_length);
    }
    else if (!inet_aton(hostOrIp, &dest_addr.sin_addr)){
		//memcpy( (char *)&dest_addr,(char *)&inaddr,host->h_length);
		//fprintf(stderr, "unknow host:%s\n", hostOrIp);
		return false;
	}
	*sockaddr = dest_addr;
	return true;
}

bool Ping::ping(std::string host, PingResult& pingResult)
{
	return ping(host, 1, pingResult);
}

bool Ping::ping(std::string host, int count, PingResult& pingResult)
{
	struct protoent *protocol;
	int size = 50 * 1024;
	IcmpEchoReply icmpEchoReply;

	m_nsend = 0;
	m_nreceived = 0;
	pingResult.icmpEchoReplys.clear();
	m_maxPacketSize = count;
	m_pid = getpid();

	pingResult.dataLen = m_datalen;
	
	if( (protocol = getprotobyname("icmp") )==NULL)
	{   
		perror("getprotobyname");
		return false;
	}

    if( (m_sockfd = socket(AF_INET,SOCK_RAW,protocol->p_proto) ) < 0)
	{       
		//perror("socket error");
		extern int errno;
		pingResult.error = strerror(errno);
		return false;
	}

    setsockopt(m_sockfd,SOL_SOCKET,SO_RCVBUF,&size,sizeof(size) );

    if (!getsockaddr(host.c_str(), &m_dest_addr))
    {
		pingResult.error = "unknow host " + host;
		return false;
	}
	pingResult.ip = inet_ntoa(m_dest_addr.sin_addr);
    sendPacket();
    recvPacket(pingResult);
	pingResult.nsend = m_nsend;
	pingResult.nreceived = m_nreceived;
	close(m_sockfd);
	return true;

}
