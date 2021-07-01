Assignment4: main1.o dbugSorts.o
	g++ -std=c++11 main1.o dbugSorts.o -o Assignment4

main1.o: main1.cpp
	g++  -std=c++11 main1.cpp -c -o main1.o
	
dbugSorts.o: dbugSorts.cpp dbugSorts.h
	g++ -std=c++11 dbugSorts.cpp -c -o dbugSorts.o

clean: 
	rm *.o Assignment4
