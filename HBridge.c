/*H-Bridge + 2 DC motors  controlled by 2 potentiometers 
and 2 switches .
 Modified and adapted from http://itp.nyu.edu/physcomp/
by GuilleTron 2010 */

const int switchPin = 2;    // switch input 
const int switchPin2  = 5;   // switch input 2 
  const int motor1Pin = 3;    // H-bridge leg 1 (pin 2, 1A)
  const int motor2Pin = 4;    // H-bridge leg 2 (pin 7, 2A)
  const int motor3Pin = 6;     // H-bridge leg 3 (pin 15, 4A)
  const int motor4Pin = 7;     // H-bridge leg 4 ( pin 10, 3A)
  const int enablePin = 9;    // H-bridge enable pin
  const int enablePin2 = 10;    // H-bridge enable pin2
  const int ledPin = 13;      // LED ----------
  const int potPin = 0;           // Analog in 0 connected to the potentiometer
  const int potPin2 = 1;          //A nalog in 1 connected to the potentiometer
  int potValue = 0;   // value returned from the potentiometer1
  int potValue2 = 1;  // value returned from the potentiometer2
  
  void setup() {
    // set the switch as an input:
    pinMode(switchPin, INPUT); 
    pinMode(switchPin2, INPUT);
    pinMode(enablePin, OUTPUT);// set  the transistor pin as output:
    pinMode(enablePin2,OUTPUT);
    // set all the other pins you're using as outputs:
    pinMode(motor1Pin, OUTPUT); 
    pinMode(motor2Pin, OUTPUT); 
    pinMode(motor3Pin, OUTPUT);
    pinMode(motor4Pin, OUTPUT);
    pinMode(enablePin, OUTPUT);
    pinMode(enablePin2, OUTPUT);
    pinMode(ledPin, OUTPUT);

    // set enablePin high so that motor can turn on:
    digitalWrite(enablePin, HIGH);
    digitalWrite(enablePin2, HIGH); 

    // blink the LED 3 times. This should happen only once.
    // if you see the LED blink three times, it means that the module
    // reset itself,. probably because the motor caused a brownout
    // or a short.
    blink(ledPin, 3, 100);
  }

  void loop() {
    
    
    // read the potentiometer, convert it to 0 - 255:
   potValue = analogRead(potPin) / 4;
   potValue2 = analogRead(potPin2)/ 4;
   // use that to control the transistor:
    analogWrite(9, potValue);
    analogWrite (10, potValue2);
    
    // if the switch is high, motor will turn on one direction:
    if (digitalRead(switchPin) == HIGH) {
      digitalWrite(motor1Pin, LOW);   // set leg 1 of the H-bridge low
      digitalWrite(motor2Pin, HIGH);  // set leg 2 of the H-bridge high
    } 
    // if the switch is low, motor will turn in the other direction:
    else {
      digitalWrite(motor1Pin, HIGH);  // set leg 3 of the H-bridge high
      digitalWrite(motor2Pin, LOW);   // set leg 4 of the H-bridge low
    }
  
 if (digitalRead(switchPin2) == HIGH) {
      digitalWrite(motor3Pin, LOW);   // set leg 3 of the H-bridge low
      digitalWrite(motor4Pin, HIGH);  // set leg 4 of the H-bridge high
    } 
    // if the switch is low, motor will turn in the other direction:
    else {
      digitalWrite(motor3Pin, HIGH);  // set leg 3 of the H-bridge high
      digitalWrite(motor4Pin, LOW);   // set leg 4 of the H-bridge low
    }
  }
  
  /*
    blinks an LED
   */
  void blink(int whatPin, int howManyTimes, int milliSecs) {
    int i = 0;
    for ( i = 0; i < howManyTimes; i++) {
      digitalWrite(whatPin, HIGH);
      delay(milliSecs/2);
      digitalWrite(whatPin, LOW);
      delay(milliSecs/2);
    }
  }
