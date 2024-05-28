#include <Servo.h>

Servo myservo1;
Servo myservo2;

const int trigpin = 11;
const int echopin = 7;

long duration;
int distance;

void setup() {
  // put your setup code here, to run once:
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);

  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);

  Serial.begin(9600);

  myservo1.attach(8);
  myservo2.attach(9);
}

void loop() {


  //clear the trigPin
  digitalWrite(trigpin, LOW);
  delayMicroseconds(2);

  // trigger the sensor
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);

  // read inputs
  duration = pulseIn(echopin, HIGH);
  distance = duration * 0.034 / 2;

  //print distance
  Serial.print("Distance: ");
  Serial.println(distance);

  //check for false data
  if (distance >= 0 && distance <= 500) {
    //map data
    int x = map(distance, 0, 500, 0, 180);

    myservo1.write(distance);
    myservo2.write(distance);
  }

  // for (int pos = 0; pos <= 180; pos++) {
  //   myservo1.write(pos);
  //   myservo2.write(pos);
  //   delay(10);
  // }
  // // delay(1000);
  // for (int pos = 180; pos >= 0; pos--) {
  //   myservo1.write(pos);
  //   myservo2.write(pos);
  //   delay(10);
  // }
  // // delay(1000);
}