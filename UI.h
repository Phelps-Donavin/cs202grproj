#ifndef UI_H
#define UI_H
#include<iostream>
#include<iomanip>
#include<fstream>

class UI{
    int runFlag;
    std::string fileName;
    std::string outputFileName;
    int userChoice;
 public:
    void printMenuHeader();//prints menu header, after terminal is cleared
    void startMenu(); //prints the start menu
    void processorMenu(); //prints out processor menu
    bool checkForFile(); //checks if file is open
    void setFileName(std::string name); //sets filename
    std::string getFileName(); // returns fle name
    void setOutputFilename(std::string name);
    std::string getOutputFilename(); //returns output file name
    int getRunFlag();
    int getuserchoice();




};


#endif