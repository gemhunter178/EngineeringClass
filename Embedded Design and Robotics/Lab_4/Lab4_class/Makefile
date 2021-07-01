wiimoteBtn: main.o WiimoteBtns.o
	g++ main.o WiimoteBtns.o -o wiimoteBtn
wiimoteAccel:
	g++ main.cpp WiimoteAccel.cpp -o wiimoteAccel

WiimoteToLed: main4.o WiimoteAccel.o ZedBoard.o
	g++ main4.o WiimoteAccel.o ZedBoard.o -o WiimoteToLed 

main.o: main.cpp
	g++ main.cpp -c -o main.o

main4.o: main4.cpp
	g++ main4.cpp -c -o main4.o

ZedBoard.o: ZedBoard.cpp
	g++ ZedBoard.cpp -c -o ZedBoard.o

WiimoteBtns.o: WiimoteBtns.cpp WiimoteBtns.h
	g++ WiimoteBtns.cpp -c -o WiimoteBtns.o

clean: 
	rm *.o wiimoteBtn wiimoteAccel
