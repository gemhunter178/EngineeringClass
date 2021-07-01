#include <iostream>
#include <string>
using namespace std;

//global variable id #
unsigned int id_num;

// Linked List Management Code
struct Person
{
	// Unique identifier for the person
	int id;
	// Information about person
	string name;
	int age;
	// Pointer to next person in list
	Person *next;
};
struct List
{
	// First person in the list. A value equal to NULL indicates that the
	// list is empty.
	Person *head;
	// Current person in the list. A value equal to NULL indicates a
	// past-the-end position.
	Person *current;
	// Pointer to the element appearing before 'current'. It can be NULL if
	// 'current' is NULL, or if 'current' is the first element in the list.
	Person *previous;
	// Number of persons in the list
	int count;
};

// Give an initial value to all the fields in the list.
void ListInitialize(List *list)
{
	list->head = NULL;
	list->current = NULL;
	list->previous = NULL;
	list->count = 0;
}
// Move the current position in the list one element forward. If last element
// is exceeded, the current position is set to a special past-the-end value.
void ListNext(List *list)
{
	if (list->current)
	{
		list->previous = list->current;
		list->current = list->current->next;
	}
}
// Move the current position to the first element in the list.
void ListHead(List *list)
{
	list->previous = NULL;
	list->current = list->head;
}
// Get the element at the current position, or NULL if the current position is
// past-the-end.
Person *ListGet(List *list)
{
	return list->current;
}
// Set the current position to the person with the given id. If no person
// exists with that id, the current position is set to past-the-end.
void ListFind(List *list, int id)
{
	ListHead(list);
	while (list->current && list->current->id != id)
		ListNext(list);
}
// Insert a person before the element at the current position in the list. If
// the current position is past-the-end, the person is inserted at the end of
// the list. The new person is made the new current element in the list.
void ListInsert(List *list, Person *person)
{
	// Set 'next' pointer of current element
	person->next = list->current;
	// Set 'next' pointer of previous element. Treat the special case where
	// the current element was the head of the list.
	if (list->current == list->head)
		list->head = person;
	else
		list->previous->next = person;
	// Set the current element to the new person
	list->current = person;
}
// Remove the current element in the list. The new current element will be the
// element that appeared right after the removed element.
void ListRemove(List *list)
{
	// Ignore if current element is past-the-end
	if (!list->current)
		return;
	// Remove element. Consider special case where the current element is
	// in the head of the list.
	if (list->current == list->head)
		list->head = list->current->next;
	else
		list->previous->next = list->current->next;
	// Free element, but save pointer to next element first.
	Person *next = list->current->next;
	delete list->current;
	// Set new current element
	list->current = next;
}
void PrintPerson(Person *person)
{
	cout << "Person with ID: " << person->id << endl;
	cout << "\tName: " << person->name << endl;
	cout << "\tAge: " << person->age << endl << endl;;
}

/** main function: Will create and process a linked list**/
int main() {
	List list;				// Create the main list
	ListInitialize(&list);			// Initialize the list
//*************** PUT THE REST OF YOUR CODE HERE  *****************
	//initialize id num
	id_num = 1; //1 for huan readability
	//declare input variable
	int input;
	//Print main menu only once.
	std::cout<<"Main Menu" << std::endl << std::endl;
	//run until user chooses exit
	while(true){
		//write out the menu (Note that this was made in Lab 1 and edited to fit here)
		std::cout<<"1. Add a person" << std::endl;
		std::cout<<"2. Find a person" << std::endl;
		std::cout<<"3. Remove a person" << std::endl;
		std::cout<<"4. Print the list" << std::endl;
		std::cout<<"5. Exit" << std::endl << std::endl;
		//first selection instruction
		std::cout<<"Select an option: ";
		std::cin>>input;
		//switch to show what the user selected, or exit, or invalid error message
		switch(input){
			case 1: 
			{
				//std::cout<<"You selected \"Add a person\"" << std::endl << std::endl;
				//organization cout
				cout<< endl;
				
				Person *p = new Person;
				//id num assigned
				p->id = id_num;
				//ask for persons's age and name
				cout<<"Please enter a name: ";
				cin>> p->name;
				//ask for name
				cout<<"Please enter their age: ";
				cin>> p->age;
				//use ListInsert with list and the person variable
				ListInsert(&list, p);
				//increment id_num
				id_num++;
				
				//organization cout
				cout<< endl;
				break;
			}
			case 2: 
				//std::cout<<"You selected \"Find a person\"" << std::endl << std::endl;
				//organization cout
				cout<< endl;
				
				//int for person id
				int ident;
				//ask for id to look for
				cout<< "Please enter the person's id to find: ";
				cin>> ident;
				//find id
				ListFind(&list,ident);
				//handling the case where no one is found:
				if(ListGet(&list) == NULL){
					//cout error message
					cout<<"No person found at id " << ident << "!\n";
				} else {
					//when it works...
					//print person at the get id
					PrintPerson(ListGet(&list));
				}
				
				//organization cout
				cout<< endl;
				break;
			case 3: 
				//std::cout<<"You selected \"Remove a person\"" << std::endl << std::endl;
				//organization cout
				cout<< endl;
				
				//COPIED AND EDITED FROM "find a person"
				//int for person id
				int id_rem;
				//ask for id to look for
				cout<< "Please enter the person's id for removal: ";
				cin>> id_rem;
				//find id
				ListFind(&list,id_rem);
				//handling the case where no one is found:
				if(ListGet(&list) == NULL){
					//cout error message
					cout<<"No person found at id " << ident << "!\n";
				} else {
					//when it works...
					//cout they have been removed
					cout<< ListGet(&list)->name << " at id " << ListGet(&list)->id << " HAS BEEN REMOVED" << endl;
					//remove the person at the id
					ListRemove(&list);
				}
				
				//organization cout
				cout<< endl;
				break;
			case 4: 
				//std::cout<<"You selected \"Print the list\"" << std::endl << std::endl;
				//organization cout
				cout<< endl;
				
				//start at ListHead
				ListHead(&list);
				//print everything from there
				while(list.current != NULL){
					//the actual print
					PrintPerson(ListGet(&list));
					//go to next person
					ListNext(&list);
				}
				
				//organization cout
				cout<< endl;
				break;
			case 5: 
				//exits the program. Return 0 to indicate this end condition was met
				return 0;
			default:
				//if no other case fit, option is invalid.
				std::cout<<"That is not a valid option, please choose another." << std::endl << std::endl;
				break;	
		}
	//run until "exit"
	}
	//just in case the code somehow gets here
	return 1;

} //end main
