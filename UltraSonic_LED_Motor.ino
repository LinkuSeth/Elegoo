//www.elegoo.com
//2016.12.08
#include "SR04.h"
#define TRIG_PIN 12
#define ECHO_PIN 11 //Base Electronics-Elegoo Ultrasonic sensor settings and pre-req
const int ledPin = 2; //LED Red Saying off - Not Close Enough
const int BuzzPin = 3; // LED Green On - Withing Range
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long a;
long b; //Setup for CM -> Inches (CM * 0.39370079)
void setup() {
   Serial.begin(9600);
   delay(1000);
   pinMode(ledPin, OUTPUT); //PIN OUTPUTS
   pinMode(BuzzPin, OUTPUT);
}

void loop() {
   a=sr04.Distance();
   Serial.print(a);
   Serial.println("cm");
   delay(1000); //Base Code any previous not noted
   b=sr04.Distance() * 0.39370079; // CM --> INCHES
   Serial.print(b);
   Serial.println("in");
   if (sr04.Distance() >= 20) {
    digitalWrite(ledPin, HIGH); //NOT WITHIN RANGE
    digitalWrite(BuzzPin, LOW);
   } else {
    digitalWrite(ledPin, LOW); //WITHIN RANGE
    digitalWrite(BuzzPin, HIGH);
   }
}
//end Code