proj3.exe: main.o ColorImageClass.o ColorClass.o RowColumnClass.o 
	g++ main.o ColorImageClass.o ColorClass.o RowColumnClass.o -o proj3.exe

main.o: main.cpp ColorImageClass.h
	g++ -c -g main.cpp -o main.o

ColorImageClass.o: constants.h ColorImageClass.h ColorImageClass.cpp
	g++ -c -g ColorImageClass.cpp -o ColorImageClass.o

ColorClass.o: constants.h ColorClass.h ColorClass.cpp
	g++ -c -g ColorClass.cpp -o ColorClass.o

RowColumnClass.o: constants.h RowColumnClass.h RowColumnClass.cpp
	g++ -c -g RowColumnClass.cpp -o RowColumnClass.o

clean:
	rm -f proj3.exe main.o ColorClass.o RowColumnClass.o ColorImageClass.o
