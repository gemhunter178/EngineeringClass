/*WiimoteAccel Class
* made by [me], based off of code from Blackboard
* allows reading of input from Wiimote, Lab 4 Embedded Design
* 2019, Feb 14th
*/
class WiimoteAccel{
	private:
		//file directory
		int fd;
	public:
		//constructor
		WiimoteAccel();
		
		//destructor
		~WiimoteAccel();
		
		//Listen function
		void Listen();
		
		//virtual file that can be overwritten later to print out the code and acceleration
		virtual void AccelerationEvent(int , int);
};
