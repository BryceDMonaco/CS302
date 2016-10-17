all: PA03
PA03: main.cpp City.o FlightMapV1.o
	g++ main.cpp City.o FlightMapV1.o -o PA03
FlightMapV1.o: FlightMapV1.cpp City.o
	g++ -c FlightMapV1.cpp
City.o: City.cpp
	g++ -c City.cpp
clean:
	rm -rf *.o PA03