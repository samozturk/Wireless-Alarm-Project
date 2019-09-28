
// Declaring vibration sensor's pin.
int vib_sens = 2;

void setup() {
  Serial.begin(9600);
  pinMode(vib_sens, INPUT);
  pinMode(3, OUTPUT);
}

// A function that turns on/off buzzer. We will put this into a for loop in void loop().
void alarm() {
    digitalWrite(3, HIGH);
    delay(500);
    digitalWrite(3, LOW);
    delay(50);
}


void loop() {
// Reading sensor data.
  int sensState = digitalRead(vib_sens);
// I am using serial monitor for testing purposes.
  Serial.println(sensState);
  delay(10);
// Sensor is NC(normally closed). Which means it will return 1 if nothing is happening.
// It will return 0 if sensor gets vibration.

  if (sensState == 0){
 for(int i=0; i < 15000; i++){
   alarm();
    }
 }
else{
  digitalWrite(3, LOW);
    }
  }
