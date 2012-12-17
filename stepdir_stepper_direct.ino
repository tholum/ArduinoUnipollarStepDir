
int pin1 = 8;
int pin2 = 7;
int pin3 = 6;
int pin4 = 5;

int steppin = 13;
int dirpin = 12;

int sensorPin = A0; 
int sensorValue = LOW;
int sspeed = 200;
int incomingByte = 0;
int dir = 0;
int safe = 0;
int forback = 0;
int stepval = 0;
int dirval = 0;
int temp = 0;
int next_step = 2;
int last_step = 4;
void setup(){
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
  pinMode(steppin , INPUT );
  pinMode(dirpin, INPUT);
}

void step1(){
  digitalWrite(pin1, HIGH);
  digitalWrite(pin2, LOW);
  digitalWrite(pin3, HIGH);
  digitalWrite(pin4, LOW);
  next_step = 2;
  last_step = 4;
}
void step2(){
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, HIGH);
  digitalWrite(pin3, HIGH);
  digitalWrite(pin4, LOW);
  next_step = 3;
  last_step = 1;
}
void step3(){
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, HIGH);
  digitalWrite(pin3, LOW);
  digitalWrite(pin4, HIGH);
  next_step = 4;
  last_step = 2;
}
void step4(){
  digitalWrite(pin1, HIGH);
  digitalWrite(pin2, LOW);
  digitalWrite(pin3, LOW);
  digitalWrite(pin4, HIGH);
  next_step = 1;
  last_step = 3;
}
void makestep(){
  dirval = digitalRead(dirpin);
  if( dirval == 0 ){
      forback = next_step;
  } else {
     forback = last_step; 
  }
  switch(forback){
    case 1:
      step1();
    break;
    case 2:
      step2();
    break;
    case 3:
      step3();
    break;
    case 4:
      step4();
    break;
    default:
      step1();
    break;
  } 
}
void loop(){
   stepval = digitalRead( steppin );
   if( stepval == 1 ){
       if( safe == 1 ) {
         makestep();
       }  
       safe = 0;
   } else {
       safe = 1;
   }
}

