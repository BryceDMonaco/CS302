all: PA03
PA03: PA03.cpp City.o FlightMapV1.o Stack.o FlightMapV2.o
	g++ PA03.cpp City.o FlightMapV1.o Stack.o FlightMapV2.o -o PA03
FlightMapV1.o: FlightMapV1.cpp City.o
	g++ -c FlightMapV1.cpp
City.o: City.cpp
	g++ -c City.cpp
Stack.o: Stack.cpp
	g++ -c Stack.cpp
FlightMapV2.o: FlightMapV2.cpp
	g++ -c FlightMapV2.cpp
clean:
	rm -rf *.o PA03