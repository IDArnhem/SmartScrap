// //////////////////////////////////////////////
// playing with relay boards and car electronics
// (cc) 2015 Luis Rodil-Fernandez
// //////////////////////////////////////////////

// pins in the arduino that will serve as output
int pins[] = {13, 12, 11, 10};  // this is an array
const int howManyPins = 4;
int pinidx = 0; // we will use this as an index

int timeOff = 1000; // in milliseconds (1/1000)
int timeOn = 1000;

// the code in the setup function runs only once 
// at the beginning of the execution
void setup() {
  Serial.begin(57600);
  for(int i = 0; i < howManyPins; i++) {
    pinMode(pins[i], OUTPUT);
  }
}

// the loop function runs over and over again 
// while the arduino is powered
void loop() {
  if(pinidx >= howManyPins ) {
    // set duty cicle on (high)
    for(int i = 0; i < howManyPins; i++) {
      digitalWrite(pins[i], HIGH);
      Serial.print("Switch pin ");
      Serial.print(pins[i]);
      Serial.println(" ON");
      delay(timeOn);
    }
    
    // set duty cycle off (low)
    for(int i = 0; i < howManyPins; i++) {
      digitalWrite(pins[i], LOW);
      Serial.print("Switch pin ");
      Serial.print(pins[i]);
      Serial.println(" OFF");
      delay(timeOff);
    }
    pinidx = 0;
  } else {  
    digitalWrite(pins[pinidx], HIGH);
      Serial.print("Switch pin ");
      Serial.print(pins[pinidx]);
      Serial.println(" ON");
    delay(timeOn);
    digitalWrite(pins[pinidx], LOW);
      Serial.print("Switch pin ");
      Serial.print(pins[pinidx]);
      Serial.println(" OFF");
    delay(timeOff);
    pinidx++;
  }
}

