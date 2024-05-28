#include <Servo.h>

Servo myservo1;
Servo myservo2;

void setup() {
  // put your setup code here, to run once:
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);

  myservo1.attach(8);
  myservo2.attach(9);
}

void loop() {

  // digitalWrite(3, HIGH);
  // digitalWrite(4, LOW);
  // delay(1000);
  // digitalWrite(4, LOW);
  // digitalWrite(3, HIGH);
  // delay(1000);


  for (int pos = 0; pos <= 180; pos++) {
    myservo1.write(pos);
    myservo2.write(pos);
    delay(10);
  }
  // delay(1000);
  for (int pos = 180; pos >= 0; pos--) {
    myservo1.write(pos);
    myservo2.write(pos);
    delay(10);
  }
  // delay(1000);
}