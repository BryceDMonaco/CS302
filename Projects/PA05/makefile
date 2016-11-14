all: PA05
PA05: PA05.cpp ArrayQueueBank.o LinkQueueBank.o NodeBank.o Client.o CountingSort.o
	g++ PA05.cpp ArrayQueueBank.o LinkQueueBank.o NodeBank.o Client.o CountingSort.o -o PA05 -std=c++11
ArrayQueueBank.o: ArrayQueueBank.cpp Client.o
	g++ -c ArrayQueueBank.cpp Client.o
LinkQueueBank.o: LinkQueueBank.cpp NodeBank.o
	g++ -c LinkQueueBank.cpp NodeBank.o
NodeBank.o: NodeBank.cpp
	g++ -c NodeBank.cpp
Client.o: Client.cpp
	g++ -c Client.cpp
CountingSort.o: CountingSort.cpp Client.o
	g++ -c CountingSort.cpp Client.o
clean:
	rm -rf *.o PA05