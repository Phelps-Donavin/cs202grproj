#ifndef NORMALIZATION_H
#define NORMALIZATION_H

#include"processor.h"
#include<iostream>
#include<vector>

class Normalization: public processor{
    float maxValue=-1;
protected:
    int bitFlag;
    int numSamples;
    std::vector<float> dataForProcessing;
public:
    Normalization()=default;
    Normalization(unsigned char* pBufferArray, int bitType, int dataBytes); //copies buffer array into the vector dataForProcessing, checks bit type to write to appropriate buffer
    Normalization(short* pBufferArray, int bitType, int dataBytes);
    virtual void process(); //normalizes audio, main component of this processing class
    std::vector<float> getData(); 
    void setDataForProcessing(unsigned char *pBufferArray, int bitType, int dataBytes); // sets the vector buffer, inherited classes can call this to set their own dataForProcessing vectors
    void setDataForProcessing(short* pBufferArray, int bitType, int dataBytes);
};
#endif