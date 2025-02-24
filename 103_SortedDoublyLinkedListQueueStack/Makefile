proj4.exe: main.o SortedListClass.o LIFOStackClass.o FIFOQueueClass.o LinkedNodeClass.o 
	g++ main.o SortedListClass.o LIFOStackClass.o FIFOQueueClass.o LinkedNodeClass.o -o proj4.exe
	
main.o: main.cpp SortedListClass.h LIFOStackClass.h FIFOQueueClass.h
	g++ -c -g main.cpp -o main.o

SortedListClass.o: SortedListClass.h SortedListClass.cpp 
	g++ -c -g SortedListClass.cpp -o SortedListClass.o

LIFOStackClass.o: LIFOStackClass.h LIFOStackClass.cpp 
	g++ -c -g LIFOStackClass.cpp -o LIFOStackClass.o

FIFOQueueClass.o: FIFOQueueClass.h FIFOQueueClass.cpp 
	g++ -c -g FIFOQueueClass.cpp -o FIFOQueueClass.o

LinkedNodeClass.o: LinkedNodeClass.h LinkedNodeClass.cpp 
	g++ -c -g LinkedNodeClass.cpp -o LinkedNodeClass.o

clean:
	rm -rf proj4.exe main.o SortedListClass.o LIFOStackClass.o FIFOQueueClass.o LinkedNodeClass.o 



