/*WiimoteBtns Class
* made by [me], based off of code from Blackboard
* allows reading of input from Wiimote, Lab 4 Embedded Design
* 2019, Feb 14th
*/
class WiimoteBtns{
	private:
		//file directory
		int fd;
	public:
		//constructor
		WiimoteBtns();
		
		//destructor
		~WiimoteBtns();
		
		//Listen function
		void Listen();
		
		//ButtonEvent function that prints out the code and value
		void ButtonEvent(int, int);
		
};
