#include <Servo.h>


#define Aug_Dur 500
#define drill 15000
#define bucketang 135

#define DC_in1 5
#define DC_in2 6
#define DC_in3 10
#define DC_in4 11

#define Top_Prox 2
#define Serv_Buck 9
#define Serv_Turn 3
#define Pump_Rel 4
#define Valve1_Rel 7
#define Valve2_Rel 8
String incomingbyte;
Servo Bucket;
Servo Turn;

int site = 1;
int tableang = 0;
int prox;

void setup() {
  Serial.begin (9600);

  Bucket.attach(Serv_Buck);
  Turn.attach(Serv_Turn);

  digitalWrite(DC_in1, 0);
  digitalWrite(DC_in2, 0);
  digitalWrite(DC_in3, 0);
  digitalWrite(DC_in4, 0);

  pinMode(Top_Prox, INPUT);
  pinMode(Pump_Rel, OUTPUT);
  pinMode(Valve1_Rel, OUTPUT);
  pinMode(Valve2_Rel, OUTPUT);
  
}

void loop() {
  Serial.println(prox);
  prox = digitalRead(Top_Prox);
  checkKeyboard();
}


void checkKeyboard(){
  if (Serial.available()) {
	incomingbyte = Serial.readStringUntil('\n');
    switch (incomingbyte) {
      case 'w': augUp();
      break;
      case 's': augDown();
      break;
      case 'b': augcontU();
      break;
      case 'n': augcontD();
      break;
      case 'e': downDrill_On();
      break;
      case 'q': downDrill_Off();
      break;
      case 'd': upDrill_On();
      break;
      case 'a': upDrill_Off();
      break;
      case 'z': bucket();
      break;
      case 't': pumpOn();
      break;
      case 'y': pumpOff();
      break;
      case 'g': valveOn();
      break;
      case 'h': valveOff();
      break;
      case 'r': fturn();
      break;
      case 'f': bturn();
      break;
    }
  }
}

void augUp(){
  digitalWrite(DC_in1, 1);
  delay(Aug_Dur);
  digitalWrite(DC_in1, 0);
}

void augDown(){
  digitalWrite(DC_in2, 1);
  delay(Aug_Dur);
  digitalWrite(DC_in2, 0);
}

void augcontU(){
  digitalWrite(DC_in1, 1);
  digitalWrite(DC_in2, 0);
}

void augcontD(){
  digitalWrite(DC_in1, 0);
  digitalWrite(DC_in2, 1);

}

void downDrill_On(){
  digitalWrite(DC_in3, 1);
  digitalWrite(DC_in4, 0);
}

void downDrill_Off(){
  digitalWrite(DC_in3, 0);
  digitalWrite(DC_in4, 0);
}

void upDrill_On(){
  digitalWrite(DC_in3, 0);
  digitalWrite(DC_in4, 1);
}

void upDrill_Off(){
  digitalWrite(DC_in3, 0);
  digitalWrite(DC_in4, 0);
}

void bucket(){
  Bucket.write(bucketang);
  delay(2000);
  Bucket.write(-bucketang);
}

void pumpOn(){
  digitalWrite(Pump_Rel, HIGH);
}

void pumpOff(){
  digitalWrite(Pump_Rel, LOW);
}

void valveOn(){
  if(site==1){
    digitalWrite(Valve1_Rel, HIGH);
  }
  else{
    digitalWrite(Valve2_Rel, HIGH);
  }
}

void valveOff(){
  if(site==1){
    digitalWrite(Valve1_Rel, LOW);
    site+=1;
  }
  else{
    digitalWrite(Valve2_Rel, LOW);
  }
}

void fturn(){
  tableang += 60;
  Turn.write(tableang);
}

void bturn(){
  tableang-=60;
  Turn.write(tableang);
}
