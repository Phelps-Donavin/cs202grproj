#include"echo.h"

Echo::Echo(unsigned char* pBufferArray, int bitType, int dataBytes){
    bitFlag=8;
    numSamples=dataBytes;
    for(int i=0; i <= numSamples; i++){
        dataForProcessing.push_back((float)pBufferArray[i]/255); //assign 255 to macro
    }
}
Echo::Echo(short* pBufferArray, int bitType, int dataBytes){
    bitFlag = 16;
    numSamples=dataBytes;
     for(int i=0; i <= numSamples; i++){
        dataForProcessing.push_back((float)pBufferArray[i]/32767.0); //assign 32767 to macro
    }
}

void Echo::process(int delay, float gain){
    std::vector<float> output;
    std::vector<float> inputExtended(dataForProcessing.size()*2, 0.0f);
    inputExtended.insert(inputExtended.begin(), dataForProcessing.begin(), dataForProcessing.end());
    output.reserve(inputExtended.size());
    for(int i=0; i<dataForProcessing.size()*2; i++){
        if(i>delay){
            output.push_back(inputExtended[i]+output[i-delay]);
        }else{  
            output.push_back(inputExtended[i]);
        }
    }
    dataForProcessing.clear();
    dataForProcessing=output;
    
    Normalization::process();
}
