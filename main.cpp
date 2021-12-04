#include<iostream>
#include"Wav.h"
#include"normalization.h"
#include"echo.h"
#include"gain.h"


int main(){
    Wav sound("Superidol.wav");
    int input;
    std::cout<<"Enter Mode"<<std::endl;
    std::cin>>input;

    switch(input){
      case 1 :
        if(sound.getBitDepth()==16){
         Normalization process(sound.getSixteenBitBitBuffer(), sound.getBitDepth(), sound.getDataBytes());
         process.process();
         sound.save(process.getData());
        }
        if(sound.getBitDepth()==8){
           Normalization process(sound.getEightBitBuffer(), sound.getBitDepth(), sound.getDataBytes());
          process.process();
         sound.save(process.getData());
        
        }
        break;
        case 2:
        std::cout<<"gain level?"<<std::endl;
        int level;
        std::cin>>level;
        if(sound.getBitDepth()==16){
            Gain process(sound.getSixteenBitBitBuffer(), sound.getBitDepth(), sound.getDataBytes());
            process.process(level);
            sound.save(process.getData());
            }
        if(sound.getBitDepth()==8){
           Gain process(sound.getEightBitBuffer(), sound.getBitDepth(), sound.getDataBytes());
           process.process(level);
           sound.save(process.getData());
           std::cout<<"in 8bit path 2"<<std::endl;
        
        }
        break;
        case 3:
        std::cout<<"gain level?"<<std::endl;
        float gainlevel;
        std::cin>>gainlevel;
        std::cout<<"delay?"<<std::endl;
        int delay;
        std::cin>>delay;
        if(sound.getBitDepth()==16){
            Echo process(sound.getSixteenBitBitBuffer(), sound.getBitDepth(), sound.getDataBytes());
            process.process(delay, gainlevel);
            sound.save(process.getData());
            }
        if(sound.getBitDepth()==8){
           Echo process(sound.getEightBitBuffer(), sound.getBitDepth(), sound.getDataBytes());
           process.process(delay, gainlevel);
           sound.save(process.getData());
        }
        break;
    }
    
    return(0);



}