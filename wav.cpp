#include"Wav.h"

   
    Wav::Wav(std::string filename){
        read(filename);
    }

    
    void Wav::read(const std::string fileName) { 
    std::ifstream file(fileName,std::ios::binary | std::ios::in); 
    if(file.is_open()){ 
        file.read((char*)&waveHeader, sizeof(wav_header));
            if(getBitDepth()==8){
                eightBitBuffer = new unsigned char[waveHeader.data_bytes];
                file.read((char*)eightBitBuffer, waveHeader.data_bytes); 
            } else {
                sixteenBitBuffer = new short[waveHeader.data_bytes];
                file.read((char*)sixteenBitBuffer, waveHeader.data_bytes);
            } 
        }
        file.close(); 
        displayMetaData(fileName);
        } 

  
    void Wav::save(std::vector<float> data){
        if(waveHeader.bit_depth==16){
        short* writeBuffer;
        writeBuffer= new short[data.size()];
        for(int i=0; i<=data.size(); i++){
            writeBuffer[i]=data[i];
        }
        waveHeader.data_bytes=data.size();
        waveHeader.wav_size=36+waveHeader.data_bytes;
         std::ofstream file("output.wav",std::ios::binary | std::ios::out); 
         file.write((char*)&waveHeader, sizeof(wav_header));
         file.write((char*)writeBuffer, waveHeader.data_bytes); 
         file.close(); 
        }

        if(waveHeader.bit_depth==8){
            unsigned char* writeBuffer;
            writeBuffer= new unsigned char[data.size()];
            for(int i=0; i<=data.size(); i++){
               writeBuffer[i]=data[i];
            }
            waveHeader.data_bytes=data.size();
            waveHeader.wav_size=36+waveHeader.data_bytes;
            std::ofstream file("output.wav",std::ios::binary | std::ios::out); 
            file.write((char*)&waveHeader, sizeof(wav_header));
            file.write((char*)writeBuffer, waveHeader.data_bytes); 
            file.close(); 
        }
    }


   void Wav::displayMetaData(std::string filename){
        std::cout<<"**FILE METADATA**"<<std::endl;
        std::cout<<filename<<std::endl;
        std::cout<<waveHeader.sample_rate<<std::endl;
        std::cout<<waveHeader.bit_depth<<std::endl;

        if(waveHeader.num_channels==1){
            std::cout<<"Mono"<<std::endl;
        }

        if(waveHeader.num_channels==2){
            std::cout<<"Stereo"<<std::endl;
        }

    }

    
    unsigned char* Wav::getEightBitBuffer() const{
        return(eightBitBuffer);
    }

    short* Wav::getSixteenBitBitBuffer() const{
        return(sixteenBitBuffer);
    }
   
    wav_header Wav::getwaveHeader(){
        return(waveHeader);
    }

    int Wav::getBitDepth(){
        return(waveHeader.bit_depth);
    }

    int Wav::getDataBytes(){
        return(waveHeader.data_bytes);
    }
    int Wav::getNumSamples(){
        return(waveHeader.data_bytes/waveHeader.sample_alignment);
    }

    Wav::~Wav(){
        if(waveHeader.data_bytes==8){
            delete[] eightBitBuffer;
        }
        if(waveHeader.data_bytes==16){
            delete[] sixteenBitBuffer;
        }
        
    }