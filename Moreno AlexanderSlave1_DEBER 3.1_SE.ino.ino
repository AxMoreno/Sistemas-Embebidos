/*
 * CAPITULO III: MODULOS DE COMUNICACIÓN I2C
 * DEBER 3.1_SE
 * TEMA: Comunicación I2C
 * NOMBRE:Alexander Moreno         
 */
//--------------------SLAVE1---------------------------------------

#include <Wire.h>
 char dato;
 const int led1=10;      //led1 pin8
 const int led2=9;      //led1 pin9
 const int led3=8;     //led1 pin10
 
void setup() {
  Wire.begin(4);        // id Slave
  Wire.onReceive(receiveEvent);
  Serial.begin(9600);
  pinMode(led1,OUTPUT);   //pin8 como salida
  pinMode(led2,OUTPUT);   //pin9 como salida
  pinMode(led3,OUTPUT);   //pin10 como salida
  
}

void loop() {
}


void receiveEvent(int bytes){
  while(Wire.available()){
    dato=Wire.read();
    switch(dato){
      case '4':
      digitalWrite(led3,HIGH);
      delay(10000);
      digitalWrite(led3,LOW);
      delay(10000);
      digitalWrite(led2,HIGH);
      delay(10000);
      digitalWrite(led2,LOW);
      delay(10000);
      digitalWrite(led1,HIGH);
      delay(10000);
      digitalWrite(led1,LOW); 
      case '5':
      digitalWrite(led1,LOW);
      digitalWrite(led2,LOW);
      digitalWrite(led3,LOW);
      break;
       case '6':
      digitalWrite(led1,LOW);
      digitalWrite(led2,LOW);
      digitalWrite(led3,LOW);
      break;
      
       default:
      digitalWrite(led1,LOW);
      digitalWrite(led2,LOW);
      digitalWrite(led3,LOW);
      break;
    }
  }
}
