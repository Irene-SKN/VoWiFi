#!/bin/bash
#openssl genrsa 2048 > key.pem
#openssl req -new -batch -config test.conf -key key.pem | openssl x509 -days 3650 -req -signkey key.pem > cert.pem
#openssl genrsa 2048 > rootCA.key.pem
#openssl req -x509 -new -batch -config test.rootCA.conf -key rootCA.key.pem -days 1024 > rootCA.cert.pem
#openssl genrsa 2048 > client.key.pem
#openssl req -new -batch -config test.conf -key client.key.pem | openssl x509 -days 370 -req -CA rootCA.cert.pem -CAkey rootCA.key.pem -CAcreateserial > client.cert.pem
LD_LIBRARY_PATH=/data/bin
./testDemo






   
