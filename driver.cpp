#include<iostream>
#include"Wav.h"
#include"normalization.h"
#include"echo.h"
#include"gain.h"
#include "UI.h"


int main(){
    std::system("clear");
    UI menu;
    do{
        menu.startMenu();
        if(menu.getRunFlag()==1){
            menu.checkForFile();
            Wav sound(menu.getFileName());
            menu.processorMenu();
            
            switch(menu.getuserchoice()){
                 case 1 :
                    if(sound.getBitDepth()==16){
                     Normalization process(sound.getSixteenBitBitBuffer(), sound.getBitDepth(), sound.getDataBytes());
                     process.process();
                     sound.save(process.getData(), menu.getOutputFilename());
                    }
                    if(sound.getBitDepth()==8){
                        Normalization process(sound.getEightBitBuffer(), sound.getBitDepth(), sound.getDataBytes());
                        process.process();
                        sound.save(process.getData(), menu.getOutputFilename());
                    }
                        break;
                 case 2:
                    std::cout<<" Please Enter Gain Level:";
                    float level;
                    std::cin>>level;
                    std::system("clear");
                    if(sound.getBitDepth()==16){
                        Gain process(sound.getSixteenBitBitBuffer(), sound.getBitDepth(), sound.getDataBytes());
                        process.process(level);
                        sound.save(process.getData(),menu.getOutputFilename());
                    }
                    if(sound.getBitDepth()==8){
                        Gain process(sound.getEightBitBuffer(), sound.getBitDepth(), sound.getDataBytes());
                        process.process(level);
                        sound.save(process.getData(), menu.getOutputFilename());
                        std::cout<<"in 8bit path 2"<<std::endl;
        
                    }
                        break;
                case 3:
                    std::cout<<"Please enter gain level:";
                    float gainlevel;
                    std::cin>>gainlevel;
                    std::cout<<"Please enter delay:";
                    int delay;
                    std::cin>>delay;
                    std::system("clear");
                    if(sound.getBitDepth()==16){
                        Echo process(sound.getSixteenBitBitBuffer(), sound.getBitDepth(), sound.getDataBytes());
                        process.process(delay, gainlevel);
                        sound.save(process.getData(), menu.getOutputFilename());
                    }
                    if(sound.getBitDepth()==8){
                        Echo process(sound.getEightBitBuffer(), sound.getBitDepth(), sound.getDataBytes());
                        process.process(delay, gainlevel);
                        sound.save(process.getData(), menu.getOutputFilename());
                    }
                        break;
            }
        }
        std::system("clear");
    }while(menu.getRunFlag()==1);
    return(0);



}