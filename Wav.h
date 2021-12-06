#ifndef WAV_H
#define WAV_H

#include <iostream>
#include <string.h>
#include "wavHeader.h"
#include <fstream>
#include <iostream>
#include <vector>
class Wav{
    /**
     * @brief the header of the wave file
     * 
     */
    wav_header waveHeader;
    /**
     * @brief if data is 8bit, it is stored in this buffer
     * 
     */
    unsigned char* eightBitBuffer;
    /**
     * @brief if the data is 16bit, it is sotred in this buffer
     * 
     */
    short* sixteenBitBuffer;
public:
    /**
     * @brief Construct a new Wav object
     * 
     */
    Wav()=default;
    /**
     * @brief  Overloaded Constructor aof the wav class, takes in a fileName to load a file
     * 
     * @param filename 
     */
    Wav(std::string filename);
    /**
     * @brief reads in a wav file
     * 
     * @param fileName name of the file to be read in
     */
    void read(const std::string fileName);
    /**
     * @brief saves the wav header and sound data to a file
     * 
     * @param data vector of floats holding the raw sound data
     * @param Filename the name of the file to be written to
     */
    void save(std::vector<float> data, std::string Filename);
    /**
     * @brief displays file metadata
     * 
     * @param filename 
     */
    void displayMetaData(std::string filename);
    /**
     * @brief Get the pointer to Eight Bit Buffer object
     * 
     * @return unsigned* 
     */
    unsigned char* getEightBitBuffer() const;
    /**
     * @brief Get pointer to the Sixteen Bit Bit Buffer object
     * 
     * @return short* 
     */
    short* getSixteenBitBitBuffer() const;
    /**
     * @brief Get the Wave Header object
     * 
     * @return wav_header 
     */
    wav_header getwaveHeader();
    /**
     * @brief Get the Bit Depth object
     * 
     * @return int 
     */
    int getBitDepth();
    /**
     * @brief Get the Data Bytes object
     * 
     * @return int 
     */
    int getDataBytes();
    /**
     * @brief Get the number of samples
     * 
     * @return int 
     */
    int getNumSamples();
    /**
     * @brief Destroy the Wav object, in particular the dynamically allocated pointers
     * 
     */
    ~Wav();
};
#endif
