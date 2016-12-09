all: PA07
PA07: PA07.cpp RedBlackTree.o
	g++ PA07.cpp RedBlackTree.o -o PA07 -std=c++11
RedBlackTree.o: RedBlackTree.cpp
	g++ RedBlackTree.cpp -c
clean:
	rm -rf *.o PA07