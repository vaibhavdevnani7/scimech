#include <Servo.h>

#define syrTime 1630

#define DC_Rel 8
#define serv 9

Servo Table;
String incomingbyte;

int site = 1;
int ang = 0;

void setup() {
  Serial.begin (9600);

  Table.attach(serv);
  Table.write(ang);
 
  pinMode(DC_Rel, OUTPUT);

}

void loop() {
  checkKeyboard();
}


void checkKeyboard(){
  if (Serial.available()) {
incomingbyte = Serial.readStringUntil('\n');
    switch (incomingbyte) {
      case 'i': waterTurn();
      break;
      case 'o': syrTurn();
      break;
      case 'p': syr();
      break;
      case 'l': site_change();
      break;
//      case 'q': augDrill_Off();
//      case 'z': Bucket();
//      case 't': pumpOn();
//      case 'y': pumpOff();
//      case 'g': valveOn();
//      case 'h': valveOff();
//      case 'r': Turn();
    }
  }
}

void waterTurn(){
  if(site==1){
    ang+=30;
    Table.write(ang);
    Serial.println(ang);
  }
  else{
    ang-=30;
    Table.write(ang);
    Serial.println(ang);
  }
}

void syrTurn(){
  if(site==1){
    ang+=120;
    Table.write(ang);
    Serial.println(ang);
  }
  else{
    ang-=120;
    Table.write(ang);
    Serial.println(ang);
  }
}

void syr(){
  digitalWrite(DC_Rel, 1);
  delay(syrTime);
  digitalWrite(DC_Rel,0);
}

void site_change(){
  if(site==1) {
    site += 1;
  }
  else if(site==2) {
    site -= 1;
  }
  Serial.print("site=");
  Serial.println(site);
}
