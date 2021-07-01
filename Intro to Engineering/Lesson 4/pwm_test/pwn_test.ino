//most of these are for organization's sake
const int redLight = 11;
int greenLight = 10;
int blueLight = 9;
int redV = 0;
int greenV = 0;
int blueV = 0;
int timer = 0;
void setup() {
  pinMode(redLight,OUTPUT);
  pinMode(greenLight,OUTPUT);
  pinMode(blueLight,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(redLight,redV);
  analogWrite(greenLight,greenV);
  analogWrite(blueLight,blueV);
  if(timer < 255){
    redV++;
  }
  if(timer > 127 && timer < (127+255)){
    greenV++;
  }
  if(timer > 255 && timer < 510){
    blueV++;
  }
  if(timer > 510 && timer < 765){
    redV--;
  }
  if(timer > 765 && timer < 1020){
    greenV--;
  }
  if(timer > 1020 && timer < 1275){
    blueV--;
  }
  if(timer < 1500){
    timer++;
  } else {
    timer = 0;
  }
  delay(10);
}
