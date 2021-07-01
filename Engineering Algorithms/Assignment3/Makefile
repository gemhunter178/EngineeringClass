Assignment3: main.o ArrayStack.o Dec2Bin.o
	g++ -std=c++11 main.o Dec2Bin.o ArrayStack.o -o Assignment3

main.o: main.cpp
	g++  -std=c++11 main.cpp -c -o main.o

Dec2Bin.o: Dec2Bin.cpp Dec2Bin.h
	g++ -std=c++11 Dec2Bin.cpp -c -o Dec2Bin.o
	
ArrayStack.o: ArrayStack.cpp ArrayStack.h
	g++ -std=c++11 ArrayStack.cpp -c -o ArrayStack.o

clean: 
	rm *.o main
