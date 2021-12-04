#ifndef GAIN_H
#define GAIN_H

#include"normalization.h"

class Gain: public Normalization{

public:
Gain(unsigned char* pBufferArray, int bitType, int dataBytes);
Gain(short* pBufferArray, int bitType, int dataBytes);
void process(int gainfactor);

};

#endif 