//Main file for assignment 4
#include "WiimoteAccel.h"
#include "ZedBoard.h"
//for rounding if need be
#include <cmath>

class WiimoteToLed: public WiimoteAccel{
	private:
		ZedBoard *zed;
	public:
		WiimoteToLed(ZedBoard *Z){
			zed = Z;
		}
		
		//override virtual
		void AccelerationEvent(int code, int acceleration){
			if(code==3){
				if(abs(acceleration) > 100){
					//sign does not matter as it leads to same LED output
					acceleration = 100;
				}
				acceleration = (int) round(abs(acceleration/12.5));
				zed->WriteAllLeds(zed->getpBase(), 2^acceleration - 1);
			}
		}
};
int main()
{
// Instantiate ZedBoard object statically
ZedBoard zed_board;
// Instantiate WiimoteToLed object statically, passing a pointer to the
// recently created ZedBoard object.
WiimoteToLed wiimote_to_led(&zed_board);
// Enter infinite loop listening to events. The overridden function
// WiimoteToLed::AccelerationEvent() will be invoked when the user moves
// the Wiimote.
wiimote_to_led.Listen();
// Unreachable code, previous function has an infinite loop
return 0;
}
