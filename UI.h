#ifndef UI_H
#define UI_H
#include<iostream>
#include<iomanip>
#include<fstream>

class UI{
    /**
     * @brief sets a runflag to tell if user wants to exit or start 
     * 
     */
    int runFlag;
    /**
     * @brief  input filename
     * 
     */
    std::string fileName;
    /**
     * @brief output filename
     * 
     */
    std::string outputFileName;
    /**
     * @brief user's processor choice
     * 
     */
    int userChoice;
 public:
    /**
     * @brief prints the start menu header
     * 
     */
    void printMenuHeader();//prints menu header, after terminal is cleared
    /**
     * @brief displays the start menu and handles user input
     * 
     */
    void startMenu(); //prints the start menu
    /**
     * @brief prints out the processor menu and handles user input
     * 
     */
    void processorMenu(); //prints out processor menu
    /**
     * @brief checks to see if the file is open and is a wav file
     * 
     * @return true 
     * @return false 
     */
    bool checkForFile(); //checks if file is open
    /**
     * @brief Sets fileName
     * 
     * @param name 
     */
    void setFileName(std::string name); //sets filename
    /**
     * @brief Gets the fileName
     * 
     * @return std::string 
     */
    std::string getFileName(); // returns fle name
    /**
     * @brief Set the Output Filename object
     * 
     * @param name the name you want to set outputFile
     */
    void setOutputFilename(std::string name);
    /**
     * @brief Gets outputFileName
     * 
     * @return std::string 
     */
    std::string getOutputFilename(); //returns output file name
    /**
     * @brief Gets runFlag
     * 
     * @return int 
     */
    int getRunFlag();
    /**
     * @brief gets users choice for the processor
     * 
     * @return int 
     */
    int getuserchoice();




};


#endif