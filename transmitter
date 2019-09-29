#include  <SPI.h> 
#include "nRF24L01.h"
#include "RF24.h"     //Adding libraries.

int mesaj[1];      //defining and array "mesaj"
RF24 verici(9,10);     //defining pins CE(chip enable) and CSN(chip select not)
const uint64_t kanal = 0xE8E8F0F0E1LL; //defining communication channel
int micsensor= 6;   // defining sensor pin.
int mic_state;


void setup(void)
{
 Serial.begin(9600);
 verici.begin();       //starting nrf
 verici.openWritingPipe(kanal);  //defininf channel id
 pinMode(micsensor, INPUT);
}


void loop(void){
mic_state = digitalRead(micsensor);
Serial.println(mic_state);

 if (digitalRead(micsensor) == LOW)
 { 
 mesaj[0] = 123; 
 verici.write(mesaj, 1);   //sending "mesaj" variable
 } else{
  mesaj[0] = 321; 
 verici.write(mesaj, 1);   //sending "mesaj" variable
 }
}
