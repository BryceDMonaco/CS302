all: QueueTester
QueueTester: QueueTester.cpp ArrayQueue.o LinkQueue.o Node.o
	g++ QueueTester.cpp ArrayQueue.o LinkQueue.o Node.o -o QueueTester -std=c++11
ArrayQueue.o: ArrayQueue.cpp
	g++ -c ArrayQueue.cpp
LinkQueue.o: LinkQueue.cpp Node.o
	g++ -c LinkQueue.cpp Node.o
Node.o: Node.cpp
	g++ -c Node.cpp
clean:
	rm -rf *.o QueueTester