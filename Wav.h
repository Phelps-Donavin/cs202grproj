#ifndef WAV_H
#define WAV_H

#include <iostream>
#include <string.h>
#include "wavHeader.h"
#include <fstream>
#include <iostream>
#include <vector>
class Wav{
    wav_header waveHeader;
    unsigned char* eightBitBuffer;
    short* sixteenBitBuffer;
public:
    Wav()=default;
    Wav(std::string filename);
    void read(const std::string fileName);
    void save(std::vector<float> data, std::string Filename);
    void displayMetaData(std::string filename);
    unsigned char* getEightBitBuffer() const;
    short* getSixteenBitBitBuffer() const;
    wav_header getwaveHeader();
    int getBitDepth();
    int getDataBytes();
    int getNumSamples();
    ~Wav();
};
#endif
