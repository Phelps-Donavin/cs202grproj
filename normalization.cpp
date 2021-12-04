#include"normalization.h"


Normalization::Normalization(unsigned char *pBufferArray, int bitType, int dataBytes){
    bitFlag=8;
    numSamples=dataBytes;
    for(int i=0; i <= numSamples; i++){
        dataForProcessing.push_back((float)pBufferArray[i]/255); //assign 255 to macro
    }
    //std::cout<<"bit flag|max value"<<std::endl<<bitFlag<<"|"<<maxValue<<std::endl;
} 

Normalization::Normalization(short* pBufferArray, int bitType, int dataBytes){
    bitFlag = 16;
    numSamples=dataBytes;
     for(int i=0; i <= numSamples; i++){
        dataForProcessing.push_back((float)pBufferArray[i]/32767.0); //assign 32767 to macro
    }
    //std::cout<<"bit flag|max value"<<bitFlag<<"|"<<maxValue<<std::endl;
}

void Normalization::process(){
    
    for(int i=0; i <= dataForProcessing.size(); i++){
        if(dataForProcessing[i]>maxValue){
            maxValue=dataForProcessing[i];
        }
    }
    for(int i=0; i<=dataForProcessing.size();i++){
            dataForProcessing[i]=dataForProcessing[i]/maxValue;
     }
}
 
std::vector<float> Normalization::getData(){
    if(bitFlag==8){
        for(int i=0; i<=dataForProcessing.size();i++){
            dataForProcessing[i]=dataForProcessing[i]*255;
        }
    }

    if(bitFlag==16){
        for(int i=0; i<=dataForProcessing.size();i++){
            dataForProcessing[i]=dataForProcessing[i]*32767;
        }
    }
    return(dataForProcessing);
}


void Normalization::setDataForProcessing(unsigned char *pBufferArray, int bitType, int dataBytes){

}

void Normalization::setDataForProcessing(short* pBufferArray, int bitType, int dataBytes){

}