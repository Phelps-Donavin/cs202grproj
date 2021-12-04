#include"normalization.h"
#include"gain.h"
Gain::Gain(unsigned char* pBufferArray, int bitType, int dataBytes){
    bitFlag=8;
    numSamples=dataBytes;
    for(int i=0; i <= numSamples; i++){
        dataForProcessing.push_back((float)pBufferArray[i]/255); //assign 255 to macro
    }
}
Gain::Gain(short* pBufferArray, int bitType, int dataBytes){
    bitFlag = 16;
    numSamples=dataBytes;
     for(int i=0; i <= numSamples; i++){
        dataForProcessing.push_back((float)pBufferArray[i]/32767.0); //assign 32767 to macro
    }
}
void Gain::process(int gainfactor){
    for(int i=0; i<=dataForProcessing.size();i++){
            dataForProcessing[i]=dataForProcessing[i]*gainfactor;
     }
     //Normalization::process();
}