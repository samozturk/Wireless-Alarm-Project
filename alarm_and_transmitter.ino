#include  <SPI.h> 
#include "nRF24L01.h"
#include "RF24.h"     

int mesaj[1];      
RF24 verici(9,10);     
const uint64_t kanal = 0xE8E8F0F0E1LL; /
int vib_state;
int vib_sens= 2;
int buzzer = 3;

void setup() {
  Serial.begin(9600);
  pinMode(vib_sens, INPUT);
  pinMode(3, OUTPUT);
  verici.begin();       
  verici.openWritingPipe(kanal);  
}
void transmit_alarm(){
   mesaj[0] = 123; 
   verici.write(mesaj, 1);
}

void asayis_berkemal(){
  mesaj[0] = 000; 
  verici.write(mesaj, 1);
}

void loop() {
// Reading sensor data.
  int vib_state = digitalRead(vib_sens);
// I am using serial monitor for testing purposes.
  Serial.println(vib_state);
  delay(10);

if (digitalRead(vib_sens) == LOW){
   transmit_alarm();
 for(int i=0; i < 15000; i++){
   mesaj[0] = 123; 
   verici.write(mesaj, 1);
   digitalWrite(buzzer, HIGH);
   delay(500);
   digitalWrite(buzzer, LOW);
   delay(50);
    }
 }
else{
  digitalWrite(3, LOW);
  asayis_berkemal();
    }
  }
