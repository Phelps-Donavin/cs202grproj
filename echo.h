#ifndef ECHO_H
#define ECHO_H

#include<vector>
#include"normalization.h"

class Echo: public Normalization{
public:
    /**
     * @brief Overloaded Constructor the Echo Class, for 8bit data, copies data from an array of char* to a vector of floats
     * 
     * @param pBufferArray pointer to a buffer holding 8bit raw sound data
     * @param bitType either 8 or 16, holds the bitdepth of the file
     * @param dataBytes the toltal length of the buffer held by pBufferArray
     */
    Echo(unsigned char* pBufferArray, int bitType, int dataBytes);
    /**
     * @brief Overloaded Constructor of the Echo Class, for 16bit data, copies data from an array of short int to a vector of floats
     * 
     * @param pBufferArray pointer to a buffer holding 16bit raw sound data
     * @param bitType  either 8 or 16, holds the bitdepth of the file
     * @param dataBytes the toltal length of the buffer held by pBufferArray
     */
    Echo(short* pBufferArray, int bitType, int dataBytes);
    /**
     * @brief Echoes the audio, the echo is started at when the number of samples greater than delay, and thhen gained by the gain param (Note, to find the nnumber of seconds to delay the audio multiply the sample rate by the number of seconds you want it to be delayed.)
     * 
     * @param delay The number of samples to delay the audio
     * @param gain The factor to gain the echoed audio by
     */
    void process(int delay, float gain); //echoes entire audio sample, takes 

};

#endif 