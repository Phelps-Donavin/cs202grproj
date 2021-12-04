#include "UI.h"

void UI::printMenuHeader(){
    std::cout<<"*Audio Processor*"<<std::endl;
}//prints menu header

void UI::startMenu(){
    printMenuHeader();
    std::cout<<"*Start(1) Quit(0)*"<<std::endl;
    std::cin>>runFlag;
    std::system("clear");
    if(runFlag==1){
        std::cout<<"Please input File Name: ";
        std::cin>>fileName;
        std::system("clear");
				std::cout<<"Please input output File Name: ";
				std::cin>>outputFileName;
				std::system("clear");
    }

		
    
    if(runFlag!=1 && runFlag !=0){
            std::cout<<"Please enter a valid menu option."<<std::endl;
    }
} //prints the start menu

void UI::processorMenu(){
    std::cout<<"*Processor Menu*"<<std::endl;
    std::cout<<"Please select a process."<<std::endl;
    std::cout<<"Normalize(1) Gain(2) Echo(3)"<<std::endl;
    std::cin>>userChoice;
} //prints out processor menu

bool UI::checkForFile(){
    std::ifstream file(fileName,std::ios::binary | std::ios::in); 
    if(!file.is_open()){
        std::cout<<"File not found";
        std::system("clear");
        return(false);
    }
    return(true);
} //checks if file is open

void UI::setFileName(std::string name){
    fileName=name;
} //sets filename

std::string UI::getFileName(){
    return(fileName);
} // returns fle name

void UI::setOutputFilename(std::string name){
    outputFileName=name;
} //setsoutputfilename

std::string UI::getOutputFilename(){
return(outputFileName);
} //returns output file name

int UI::getRunFlag(){
    return(runFlag);
}

int UI::getuserchoice(){
    return(userChoice);
}