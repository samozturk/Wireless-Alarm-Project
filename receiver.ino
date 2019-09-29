#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"           //adding libraries.
int mesaj[1];
RF24 alici(9,10);
const uint64_t kanal = 0xE8E8F0F0E1LL;
int led = 2;

void setup(void){
 Serial.begin(9600);
 
 alici.begin();
 alici.openReadingPipe(1,kanal);
 alici.startListening();
 pinMode(led, OUTPUT);
 }

void loop(void){
 if (alici.available())
 {
   bool done = false;    
   while (!done)
   {
     done = alici.read(mesaj, 1);      

     if (mesaj[0] == 123)
     {
       delay(10);
   digitalWrite(led, HIGH);
 }
     else {
       digitalWrite(led, LOW);
   }
     delay(10);
   }
 }
 }
