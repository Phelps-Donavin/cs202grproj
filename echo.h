#ifndef ECHO_H
#define ECHO_H

#include<vector>
#include"normalization.h"

class Echo: public Normalization{
public:
    Echo(unsigned char* pBufferArray, int bitType, int dataBytes);
    Echo(short* pBufferArray, int bitType, int dataBytes);
    void process(int delay, float gain); //echoes entire audio sample, takes 

};

#endif 