all: PA03
PA03: main.cpp City.o FlightMapV1.o Stack.o
	g++ main.cpp City.o FlightMapV1.o Stack.o -o PA03
FlightMapV1.o: FlightMapV1.cpp City.o
	g++ -c FlightMapV1.cpp
City.o: City.cpp
	g++ -c City.cpp
Stack.o: Stack.cpp
	g++ -c Stack.cpp
clean:
	rm -rf *.o PA03