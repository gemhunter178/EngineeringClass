//most of these are for organization's sake. They also allow the ease of changing ports
const int redLight = 13;
const int greenLight = 12;
const int blueLight = 11;
const int button2 = 2;
const int button3 = 3;
//these are to store the state values.
int button2state;
int button3state;

//sets up which ports are input and which are output
void setup() {
  pinMode(redLight,OUTPUT);
  pinMode(greenLight,OUTPUT);
  pinMode(blueLight,OUTPUT);
  pinMode(button2,INPUT);
  pinMode(button3,INPUT);
}

//main code
void loop() {
  //creates an infinite loop (probably redundant)
  while(true){
    //reads the input states
    button2state = digitalRead(button2);
    button3state = digitalRead(button3);
    //states the case for both buttons pressed (all lights on)
    if(button2state == LOW && button3state == LOW){
      digitalWrite(redLight,HIGH);
      digitalWrite(greenLight,HIGH);
      digitalWrite(blueLight,HIGH);
    } else {
      //outherwise, this should automatically turn off/on the right lights. Since buttons pressed would be LOW, we take the opposite for the outputs
      digitalWrite(redLight,!button2state);
      digitalWrite(greenLight,!button3state);
      digitalWrite(blueLight,LOW);
    }
  }
}
