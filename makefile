audio: main.o wav.o normalization.o gain.o echo.o
	g++ main.o wav.o normalization.o gain.o echo.o -o audio
main.o: main.cpp
	g++ main.cpp -c
wav.o: wav.cpp
	g++ wav.cpp -c
normalization.o: normalization.cpp
	g++ normalization.cpp -c
gain.o: gain.cpp
	g++ gain.cpp -c
echo.o: echo.cpp
	g++ echo.cpp -c
make clean:
	rm *.o output.wav audio