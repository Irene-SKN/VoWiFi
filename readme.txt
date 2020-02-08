编译：
cmakelist 修改工具链 的路径 
cmake ./
make && make install
在bin下会打包需要部署的程序

使用时将申请的license.sign 放在与Mtc_CliCfgSetLicenseFileName 入参对应的路径下 

主动输入pcm数据到sdk中
不需要调用这两个函数 Zmf_AudioInputStart  Zmf_AudioOutputStart
分别改为调用
音频输入
void Zmf_OnAudioInput(const char *inputId="?", int sampleRateHz=16000, int iChannels=1, unsigned char *buf, int len, int *micLevel=0, int playDelayMS=0, int recDelayMS=0, int clockDrift=0);
inputId 为自定义名称 在stop输入的函数中传入。sampleRateHz为采样频率，iChannels为声道数，buf为pcm数据，len为pcm长度，其他参数不需要改动，传默认值
//关闭通知
void Zmf_OnAudioInputDidStop       (const char *inputId="?");

主动输入pcm数据到SDK 中，因为设备采集是阻塞的，如果采集的数据是以回调的方式通知上层，只需要把回调数据 通过Zmf_OnAudioInput 喂入SDK 即可
如果是以文件的方式，在jpaudioMng 中有说明，查看代码即可
音频输出
void Zmf_OnAudioOutput(const char *outputId, int sampleRateHz=16000, int iChannels=1, unsigned char *buf, int len);
outputId为自定义名称，在stop函数中传入，sampleRateHz为所需的采样频率，iChannels为所需的声道数，buf该指针为出参，提供pcm数据，len为想要拿到的pcm长度
len的计算公式为 len = sampleRateHz * (T/1000) * Channles * 2
其中T为当前流逝的实际时间，单位为秒
该函数阻塞
//关闭通知
void Zmf_OnAudioOutputDidStop      (const char *outputId);



	
