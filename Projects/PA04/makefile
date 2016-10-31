all: PA04
PA04: PA04.cpp BubbleSort.o MergeSort.o CountingSort.o
	g++ PA04.cpp BubbleSort.o MergeSort.o CountingSort.o -o PA04 -std=c++11
BubbleSort.o: BubbleSort.cpp
	g++ -c BubbleSort.cpp
MergeSort.o: MergeSort.cpp
	g++ -c MergeSort.cpp
CountingSort.o: CountingSort.cpp
	g++ -c CountingSort.cpp
clean:
	rm -rf *.o PA04