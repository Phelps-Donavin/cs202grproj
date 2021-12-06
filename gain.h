#ifndef GAIN_H
#define GAIN_H

#include"normalization.h"

class Gain: public Normalization{

public:
/**
 * @brief Overloaded Constructor the gain class, for 8bit data
 * 
 * @param pBufferArray pointer to 8 bit buffer holding raw sound data
 * @param bitType contains 8 or 16, dependng on the file type
 * @param dataBytes contains the length of the raw sound data pointer to in pBufferArray
 */
Gain(unsigned char* pBufferArray, int bitType, int dataBytes);
/**
 * @brief Overloaded Constructor of the gain class, for 16bit data
 * 
 * @param pBufferArray pointer to 16 bit buffer holding raw sound data
 * @param bitType contains 8 or 16, dependng on the file type
 * @param dataBytes contains the length of the raw sound data pointer to in pBufferArray
 */
Gain(short* pBufferArray, int bitType, int dataBytes);
/**
 * @brief Increased all samples by gainfactor
 * 
 * @param gainfactor The factor that all samples are multiplied by
 */
void process(int gainfactor);

};

#endif 