#ifndef NORMALIZATION_H
#define NORMALIZATION_H

#include"processor.h"
#include<iostream>
#include<vector>

class Normalization: public processor{
    /**
     * @brief - max value of the samples in dataForProcessing
     * 
     */
    float maxValue=-1;
protected:
    /**
     * @brief - used to determine if data in dataForProcessing is 8 or 16 bit
     * 
     */
    int bitFlag;
    /**
     * @brief - the number of samples
     * 
     */
    int numSamples;
    /**
     * @brief - raw sound data to be processed
     * 
     */
    std::vector<float> dataForProcessing;
public:
    /**
     * @brief - Construct a new Normalization object
     * 
     */
    Normalization()=default;
    /**
     * @brief Overloaded constructor of the Normalization class constructor, copies data data froma buffer to a vector char*, sets class Bitflag attribute
     * 
     * @param pBufferArray - Pointer to a buffer holding raw 8bit sound data
     * @param bitType  - Holds either 8 or 16, representing sound data bit Depth
     * @param dataBytes - total length of raw sound data
     */
    Normalization(unsigned char* pBufferArray, int bitType, int dataBytes);
    /**
     * @brief Overloaded constrcutor of the Normlization class constructor, copies data from a buffer to a vecotr of short int, sets class Bitflag attribute
     * 
     * @param pBufferArray -Pointer to a buffer holding raw 16 bit sound data
     * @param bitType - Holds either 8 or 16, representing sound data bit Depth
     * @param dataBytes - total length of raw sound data
     */
    Normalization(short* pBufferArray, int bitType, int dataBytes);
    /**
     * @brief Normalizes audio
     * 
     */
    virtual void process();
    /**
     * @brief - Get the dataForProcessing
     * 
     * @return std::vector<float> 
     */
    std::vector<float> getData(); 
    /**
     * @brief Sets dataForProcessing, overloaded for 8bit or 16bit data
     * 
     * @param pBufferArray - Pointer to a buffer holding raw 8bit sound data
     * @param bitType - Holds either 8 or 16, representing sound data bit Depth
     * @param dataBytes - total length of raw sound data
     */
    void setDataForProcessing(unsigned char *pBufferArray, int bitType, int dataBytes);
    /**
     * @brief Sets dataForProcessing, overloaded for 8bit or 16bit data
     * 
     * @param pBufferArray - Pointer to a buffer holding raw 16bit sound data
     * @param bitType - Holds either 8 or 16, representing sound data bit Depth
     * @param dataBytes - total length of raw sound data
     */
    void setDataForProcessing(short* pBufferArray, int bitType, int dataBytes);
};
#endif