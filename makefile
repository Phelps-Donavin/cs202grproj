audio: driver.o wav.o normalization.o gain.o echo.o UI.o
	g++ driver.o wav.o normalization.o gain.o echo.o UI.o -o audio
driver.o: driver.cpp
	g++ driver.cpp -c
wav.o: wav.cpp
	g++ wav.cpp -c
normalization.o: normalization.cpp
	g++ normalization.cpp -c
gain.o: gain.cpp
	g++ gain.cpp -c
echo.o: echo.cpp
	g++ echo.cpp -c
UI.o: UI.cpp
	g++ UI.cpp -c
make clean:
	rm *.o output.wav