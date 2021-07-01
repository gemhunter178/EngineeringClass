#include <LiquidCrystal.h>

const int tmprtrPin = A0;
//if we are to set the contrast manually, this can be left in, as this pin is unused.
const int contrastPin = 9;
//I could shift the position of the output based on thsi number. I like it centered.
const int shift = 4;

//sets up the LCD ports
LiquidCrystal displ(12, 11, 5, 4, 3, 2);

void setup() {
  //actual setup
  displ.begin(16, 2);
  displ.clear();
  pinMode(tmprtrPin, INPUT);
  pinMode(contrastPin, OUTPUT);
  //this only needs to run once as well
  analogWrite(contrastPin, 125);
  
  //the following is the welcome message
  displ.setCursor(0,0);
  displ.print("Hello, welcome");
  displ.setCursor(0,1);
  displ.print("to Thermostat1!");
  //time for users to read, like a startup message
  delay(2000);
  displ.clear();
  displ.setCursor(0,0);
  displ.print("Temp will be");
  displ.setCursor(0,1);
  displ.print("displayed soon");
  delay(1500);
  
  //clears screen for temperature output
  displ.clear();
  //makes the headers for the temperature reading
  displ.setCursor(6 + shift, 0);
  //char 223 is the degree symbol
  displ.print((char)223);
  displ.setCursor(7 + shift, 0);
  displ.print("C");
  displ.setCursor(6 + shift, 1);
  displ.print((char)223);
  displ.setCursor(7 + shift, 1);
  displ.print("F");
}

void loop() {
  //write input, converted to volts to a variable
  float rawTemp = convertVolt(tmprtrPin);
  //convert volts to celsius
  float tempC = (rawTemp - 0.5)*100;
  //convert celsius to fahrenheit
  float tempF = 9.0 * tempC / 5.0 + 32.0;
  //display values
  displ.setCursor(shift,0);
  displ.print(tempC);
  displ.setCursor(shift,1);
  displ.print(tempF);
  //updates based on this delay.
  delay(200);
}

//converts analog input to volts
float convertVolt(int pin){
  return (analogRead(pin)*(5.0/1023));
}

