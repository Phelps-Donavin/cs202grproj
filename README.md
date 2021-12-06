## CS 202 Group Project

Project Type: **Base Level**

Team Members: Donavin Phelps, Austin Ah Mau, Tania Jaswal

Contributions:
Tania: UI & Doxygen
Austin Ah Mau: Processor Algorithms 
Donavin Phelps: File I/O and Processor Implementations

UML Diagrams are in Doxygen Documentation

*Issues:* Echo fails when delay is larger than the total number of sample sizes since the extended vector will try to access a -1 element of a vector which doesn't exist.

*Challenges:* This was the first time all of us had dealt with any form of Binary data, in addition to this this was the first time all of us dealt with audio files in any form. As such, much of this project was spent researching how Binary data and Audio data work independently and cooperatively. Once the elements of both were understood the project went rather smoothly. 

*Build*: Run "make" in the Linux Terminal. Use ./audio_processor  Audio is provided in the Test Sounds Directory, before running make sure any audio you want to use is in the same directory as audio_processor.