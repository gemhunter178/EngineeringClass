/*
Eng Algorithms, ASSIGNMENT 4, part 2
Author: [me]
ID: [ID withheld]
Description: One program to simulate a bank line with an amount of tellers. Uses two queues
Many parts, such as declarations, copied or based on assignment document and lecture slides
*/

#include <string> //std::string
#include <fstream> //ofstream, ifstream
#include <iostream> //for input output operations on console
#include <cassert> //assert()

//global variables
static const int waitingQCapacity = 10;
static const int eventsQCapacity = 50;
int CUST_NUM = 10;
//no other way to pass the max size of the queue on as there was no variable or passing point to handle
int maxWaitLine = 0;

//Class declarations, actual definitions are below main()

//An object for each customer
class BankCustomer
{
public:
	//ID of customer
	int ID;
	//when they arrive
	int ArrivalTime;
	//when they start being served
	int ServiceStartTime;
	//how long they need to be served for
	int TransactionLength;
	//unused constructor/deconstructor
	BankCustomer();
	~BankCustomer();
};

//An object for events
class Event
{
public:
	// 'A' for arrival and 'D' for departure
	char EventType;
	// ID of customer that made the event
	int CustID;
	// the time of the event
	int ADTime;
	// unused constructor/deconstructor
	Event();
	~Event();
};

//priority queue that holds all the events
class PQueue
{
public:
	//int c is for the capacity, must be larger than total expected events as this queue is not circular
	PQueue(int);
	~PQueue();
	//see if array is empty
	bool isEmpty(); 
	//uses listInsert to insert a new event
	bool enqueue(Event ev); 
	//calls listDelete to remove the event at the front of the queue
	bool dequeue(); 
	//uses listPeek to return queue's front event
	Event peekFront(); 

private:
	//Max size of the queue
	int QCap; 
	//pointer to an array of events
	Event* events; 
	//number of events currently in queue
	int count; 
	//insert event into sorted list
	bool listInsert(Event ev); 
	//delete event at end of list
	bool listDelete(); 
	//get event at the end of the list
	Event listPeek(); 
};

//queue that maintains the bank waiting line
class ArrayQueue
{
public:
	//passed in int is the max size of the waiting area, circular queue means as long
	//as there is room for everyone, no problems should occur
	ArrayQueue(int);
	~ArrayQueue();
	//see if queue is empty
	bool isEmpty(); 
	//add new ID to queue
	bool enqueue(const int newID); 
	//remove item at front of queue
	bool dequeue(); 
	//return item at front of queue
	int peekFront(); 
	//returns the current number of items in the queue
	int queueLength(); 
private:
	int QCap;
	// Array of queue items (the customers' IDs in this case)
	int* IDs; 
	// Index to front of queue
	int front; 
	int back; // Index to back of queue
	int count; // Number of items currently in the queue
};

//simulating actual bank teller service
class BankTellerService
{
public:
	/*added tellNum to state how many tellers to simulate with
	infS is the input file name,
	otfS is the output file name*/
	BankTellerService(std::string infS, std::string otfS, int tellerNum);
	~BankTellerService();
	/*reads the customers' arrival and transaction times
	from the input file. For each arrival data, add one customer object
	in the Customers array and insert an arrival event in the EventsQ.*/
	void readCustomersInfo();
	/*executes a loop that continues as long as there are
	events in the EventsQ. Serve each event in order and according
	to the event type (Arrival or Departure). A customer who
	receives service from an available teller, will result in
	a departure event to be inserted in the EventQ. An arrival
	event with a busy teller will result in adding the
	corresponding customer ID in the WaitingQ. A departure event
	results in serving a Customer from the WaitingQ or mark the
	teller as available (if the WaitingQ is empty)*/
	void serveCustomers();
	/*calculates the needed statistics based on the
	updated data of the customers and stores these
	statistics in the output text file.*/
	void getStatistics();

private:
	//indicates how many tellers are currently busy
	int BusyTeller; 
	//Extra: total number of tellers
	int tellNum;
	//the total number of customers in the simulation
	int CustomersNum; 
	//text file with the arrival and transaction times
	std::ifstream inf; 
	//text file with the trace messages and the final statistics
	std::ofstream otf; 
	ArrayQueue WaitingQ = ArrayQueue(waitingQCapacity);
	PQueue EventsQ = PQueue(eventsQCapacity);
	//array of the customer objects in the simulation
	BankCustomer* Customers; 
	//the maximum length of the waiting queue
	int waitingQMax = 0; 
};


/*-------------------
        MAIN
-------------------*/
int main() {
	//main function given from assignment document
	//3rd passed in variable states how many tellers to simulate
	BankTellerService myBank("input.txt", "output.txt", 1);
	myBank.readCustomersInfo();
	myBank.serveCustomers();
	myBank.getStatistics();

	//wait for user input before closing
	//std::cin.ignore();
	return 0;
}

BankCustomer::BankCustomer()
{
	//empty
}

BankCustomer::~BankCustomer()
{
	//empty
}

Event::Event()
{
	//empty
}

Event::~Event()
{
	//empty
}

PQueue::PQueue(int c)
{
	//set capacity to c
	QCap = c;
	//set count
	count = 0;
	events = new Event[QCap];
}

PQueue::~PQueue()
{
	delete[] events;
}

bool PQueue::isEmpty()
{
	return count == 0;
}

bool PQueue::enqueue(Event ev)
{
	//debug
	//std::cout << "\ninserting Customer #" << ev.CustID << " at " << ev.ADTime << " with type " << ev.EventType;
	//use listInsert to insert item into queue
	return listInsert(ev);
}

bool PQueue::dequeue()
{
	//delete item at end of list/front of queue
	return listDelete();
}

Event PQueue::peekFront()
{
	//returns item at end of the list
	return listPeek();
}

bool PQueue::listInsert(Event ev)
{
	bool done = false; //default false
	//only run if queue isn't full (or won't be overfilled from this entry)
	if (count < QCap) {
		//insertion sort into the events queue
		for (int i = count; i >= 0; i--) {
			
			if (i == 0) { //preventive measures: if at end of array, don't test [i-1]
				events[i] = ev;
				//debug
				//std::cout << "\ninserted at slot " << i;
				//break as it is done
				break;
			} else if (ev.ADTime >= events[i-1].ADTime) {//if the right spot hasn't been found yet
				//move event right
				events[i] = events[i-1];
			}
			else { //correct placement has been found
				events[i] = ev;
				//debug
				//std::cout << "\ninserted at slot " << i;
				//break as it is done
				break;
			}//end if else
		}//end for
		//increment count
		count++;
		//operation successful
		done = true;
	}//end if
	return done;
}

bool PQueue::listDelete()
{
	bool done = false; //default false
	//only run if queue isn't empty
	if (!isEmpty()) {
		//mark current count for overwriting
		count--;
		//mark successful
		done = true;
	}
	return done;
}

Event PQueue::listPeek()
{
	assert(!isEmpty()); //error if the array is empty
	//return front of queue
	return events[count-1];
}

ArrayQueue::ArrayQueue(int c)
{
	//set capacity to c
	QCap = c;
	//set count
	count = 0;
	//set other variables
	front = 0;
	back = 0;
	//create array
	IDs = new int[QCap];
}

ArrayQueue::~ArrayQueue()
{
	//delete array
	delete[] IDs;
}

bool ArrayQueue::isEmpty()
{
	//return true if count is empty
	return count == 0;
}

bool ArrayQueue::enqueue(const int newID)
{
	bool done = false; //default false
	//if array is not yet full
	if (count < QCap) {
		//so it will insert at 0 initially
		IDs[back] = newID;
		//debug
		//std::cout << "\ninserted ID #" << newID << " at " << back;
		//find next index
		back = (back + 1) % QCap;
		//place ID in next available index
		//increment count
		count++;
		//operation success
		done = true;

		//check if this is the longest the queue has been
		if (count > maxWaitLine) {
			maxWaitLine = count;
		}
	}
	return done;
}

bool ArrayQueue::dequeue()
{
	bool done = false; //default false
	//test if empty
	if (!isEmpty()) {
		//remove element at front of queue
		front = (front + 1) % QCap;
		//decrement count
		count--;
		//update result
		done = true;
	}
	return done;
}

int ArrayQueue::peekFront()
{
	assert(!isEmpty()); //error if the array is empty
	//return ID at fron of queue
	return IDs[front];
}

int ArrayQueue::queueLength()
{
	//return current number of items
	return count;
}

BankTellerService::BankTellerService(std::string infS, std::string otfS, int tellerNum)
{
	//open files
	inf.open(infS);
	otf.open(otfS);
	//make sure files are open
	assert(!inf.fail());
	assert(!otf.fail());
	//set customer number to how many customers are in the simulation
	CustomersNum = CUST_NUM;
	//make array of customers
	Customers = new BankCustomer[CustomersNum];
	//set amount of tellers
	tellNum = tellerNum;
	//set no busy tellers yet
	BusyTeller = 0;
}

BankTellerService::~BankTellerService()
{
	//close files
	inf.close();
	otf.close();
	//deallocate
	delete[] Customers;
}

void BankTellerService::readCustomersInfo()
{
	//define IDs we're giving people who walk in
	int currentID = 0;
	//string to pass into
	std::string inputStr;
	//do until EoF
	while (!inf.eof()) {
		//get for arrival time
		std::getline(inf, inputStr, ' ');
		//convert to int
		Customers[currentID].ArrivalTime = std::stoi(inputStr);
		//debug
		//std::cout << inputStr << ' ';
		//get for time needed to do transaction
		std::getline(inf, inputStr);
		//convert to int
		Customers[currentID].TransactionLength = std::stoi(inputStr);
		//fill customer's ID
		Customers[currentID].ID = currentID;
		//debug
		//std::cout << inputStr << '\n';
		//increment ID
		currentID++;
	}//end while
	//done, return
	return;
}

void BankTellerService::serveCustomers()
{
	//fill event queue
	for (int i = 0; i < CustomersNum; i++) {
		//make event object
		Event curEvent;
		//fill with correct data
		curEvent.ADTime = Customers[i].ArrivalTime;
		curEvent.CustID = Customers[i].ID;
		curEvent.EventType = 'A';
		EventsQ.enqueue(curEvent);
	}
	//output to file
	otf << "Simulation traces:\n";
	//while the eventsQ is not empty
	while (!EventsQ.isEmpty()) {
		//set current event to the first in the events queue
		Event curEvent = EventsQ.peekFront();
		//if it's an arrival event
		if (curEvent.EventType == 'A') {
			//test if there is an available teller
			if (BusyTeller < tellNum) {
				//increase BusyTeller
				BusyTeller++;
				//create Departure event based on the person being served
				Event departure;
				//luckily, the ID nums match their place in the array
				departure.ADTime = Customers[curEvent.CustID].TransactionLength + curEvent.ADTime;
				departure.CustID = curEvent.CustID;
				departure.EventType = 'D';
				//enqueue depature event
				EventsQ.enqueue(departure);
				//enter the service start time into that person
				Customers[curEvent.CustID].ServiceStartTime = curEvent.ADTime;
				//debug
				std::cout << "\nServed Customer #" << curEvent.CustID << " at time " << curEvent.ADTime << ". Will finish at " << departure.ADTime ;
			}
			else { //no available tellers
				//add customer to waiting line
				WaitingQ.enqueue(curEvent.CustID);
				//debug
				std::cout << "\nCustomer #" << curEvent.CustID << " is now in wait at time " << curEvent.ADTime;
			}//end if else
			//output to file the arrival event
			otf << "Processing an arrival event at time <-- " << curEvent.ADTime << '\n';
		}
		else if (!WaitingQ.isEmpty()) { //departure event is happening, check line for next customer
			curEvent.CustID = WaitingQ.peekFront();
			//create Departure event based on the person being served
			Event departure;
			//luckily, the ID nums match their place in the array
			departure.ADTime = Customers[curEvent.CustID].TransactionLength + curEvent.ADTime;
			departure.CustID = curEvent.CustID;
			departure.EventType = 'D';
			//enqueue the event
			EventsQ.enqueue(departure);
			//dequeue the person from the line
			WaitingQ.dequeue();
			//enter the service start time into that person
			Customers[curEvent.CustID].ServiceStartTime = curEvent.ADTime;
			//debug
			std::cout << "\nServed Customer #" << curEvent.CustID << " at time " << curEvent.ADTime << ". Will finish at " << departure.ADTime;
			//output to file the departure event
			otf << "Processing a departure event at time -->" << curEvent.ADTime << '\n';
		}
		else { //no line, but one less busy teller
			BusyTeller--;
			//debug
			std::cout << "\none more teller is available, (" << tellNum - BusyTeller << " available) at time " << curEvent.ADTime;
			//output to file the departure event
			otf << "Processing a departure event at time -->" << curEvent.ADTime << '\n';
		}//end if else if else
		//dequeue the event handled
		EventsQ.dequeue();
	}
	return;
}

void BankTellerService::getStatistics()
{
	//for console
	std::cout << "\nFinal Statistics:\n";
	//for file
	otf << "\nFinal Statistics:\n";
	//stats to be collected in this step
	float totalTime = 0;
	int maxWait = 0;
	//getting stats by iterating through all customers
	for (int i = 0; i < CustomersNum; i++) {
		//int for wait time of this customer
		int waitT = Customers[i].ServiceStartTime - Customers[i].ArrivalTime;
		//increment total waited time
		totalTime += waitT;
		//see if this was that max waiting time
		if (waitT > maxWait) {
			maxWait = waitT;
		}

	}
	//find average
	float avgWait = totalTime / CustomersNum;
	//outputs
	//console
	std::cout << "Total number of customers processed: " << CustomersNum << "\nAverage waiting time = " << avgWait << "\tMaximum waiting time = " << maxWait << '\n';
	//had to be passed by global variable as no other variables were given to store this
	std::cout << "Maximum waiting queue length = " << maxWaitLine;
	//file
	otf << "Total number of customers processed: " << CustomersNum << "\nAverage waiting time = " << avgWait << "\tMaximum waiting time = " << maxWait << '\n';
	//had to be passed by global variable as no other variables were given to store this
	otf << "Maximum waiting queue length = " << maxWaitLine;
}
