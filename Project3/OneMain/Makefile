shapeAreas.exe: shapeAreas.o Square.o Rectangle.o Triangle.o
	g++ shapeAreas.o Square.o Rectangle.o Triangle.o -o shapeAreas.exe

shapeAreas.o: shapeAreas.cpp SquareArray.h Square.h Rectangle.h Triangle.h
	g++ -c shapeAreas.cpp -o shapeAreas.o

Square.o: Square.h Square.cpp
	g++ -c Square.cpp -o Square.o

Rectangle.o: Rectangle.h Rectangle.cpp
	g++ -c Rectangle.cpp -o Rectangle.o

Triangle.o: Triangle.h Triangle.cpp
	g++ -c Triangle.cpp -o Triangle.o

clean:
	rm -f shapeAreas.exe shapeAreas.o Square.o Rectangle.o Triangle.o
