proj5.exe: ValidInputCheck.o CustomerClass.o EventClass.o random.o SimulationClass.o main.o
	g++ ValidInputCheck.o CustomerClass.o EventClass.o random.o SimulationClass.o main.o -o proj5.exe

ValidInputCheck.o: ValidInputCheck.cpp
	g++ -std=c++98 -Wall -c ValidInputCheck.cpp -o ValidInputCheck.o
CustomerClass.o: CustomerClass.cpp
	g++ -std=c++98 -Wall -c CustomerClass.cpp -o CustomerClass.o
EventClass.o: EventClass.cpp
	g++ -std=c++98 -Wall -c EventClass.cpp -o EventClass.o
random.o: random.cpp
	g++ -std=c++98 -Wall -c random.cpp -o random.o
SimulationClass.o: SimulationClass.cpp
	g++ -std=c++98 -Wall -c SimulationClass.cpp -o SimulationClass.o
main.o: main.cpp
	g++ -std=c++98 -Wall -c main.cpp -o main.o

clean:
	rm -rf ValidInputCheck.o CustomerClass.o EventClass.o random.o SimulationClass.o main.o proj5.exe