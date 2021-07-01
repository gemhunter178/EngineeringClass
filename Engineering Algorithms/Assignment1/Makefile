Assignment1: Assignment1.o Assign1Header.o getInput.o
	g++ -std=c++11 Assignment1.o getInput.o Assign1Header.o -o Assignment1

Assignment1.o: Assignment1.cpp
	g++  -std=c++11 Assignment1.cpp -c -o Assignment1.o

getInput.o: getInput.cpp getInput.h
	g++ -std=c++11 getInput.cpp -c -o getInput.o
	
Assign1Header.o: Assign1Header.cpp Assign1Header.h
	g++ -std=c++11 Assign1Header.cpp -c -o Assign1Header.o

clean: 
	rm *.o Assignment1
