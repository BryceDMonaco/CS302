all: FlightMap
FlightMap: main.cpp City.o
	g++ main.cpp City.o -o PA03
City.o: City.cpp
	g++ -c City.cpp
clean:
	rm -rf *.o FlightMap