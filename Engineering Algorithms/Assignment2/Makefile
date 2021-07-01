Assignment2: Assignment2.o Assign2Classes.o getInput.o
	g++ -std=c++11 Assignment2.o getInput.o Assign2Classes.o -o Assignment2

Assignment2.o: Assignment2.cpp
	g++  -std=c++11 Assignment2.cpp -c -o Assignment2.o

getInput.o: getInput.cpp getInput.h
	g++ -std=c++11 getInput.cpp -c -o getInput.o
	
Assign2Classes.o: Assign2Classes.cpp Assign2Classes.h
	g++ -std=c++11 Assign2Classes.cpp -c -o Assign2Classes.o

clean: 
	rm *.o Assignment2
