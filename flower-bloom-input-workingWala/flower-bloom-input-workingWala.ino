#include <Servo.h>

Servo myservo1;
int isBloom;

void setup() {
  // put your setup code here, to run once:
  // pinMode(12, OUTPUT);
  myservo1.attach(12);

  Serial.begin(9600);
  Serial.println("Enter state: (y:1 / n:2)");
}


void loop() {


  if (Serial.available() > 1) {

    isBloom = Serial.parseInt();
    Serial.println(isBloom);

    if (isBloom == 1) {
      for (int pos = 45; pos <= 180; pos++) {
        myservo1.write(pos);
        // myservo2.write(pos);
        delay(10);
      }
    }
    else if (isBloom = 2) {
      for (int pos = 180; pos >= 45; pos--) {
        myservo1.write(pos);
        // myservo2.write(pos);
        delay(10);
      }
    }
    else {
      Serial.println("Invalid input!");
    }
  }

  
}
