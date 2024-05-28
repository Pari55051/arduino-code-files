const int trigPin = 3;
const int echoPin = A0;

int red = 7;
int yellow = 12;
int green = 11;
int blue = 10;
int white = 9;

long duration;
int distance;

void setup() {
  // put your setup code here, to run once:
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);

  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(white, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  // clear the pin
  digitalWrite(trigPin, LOW);
  delay(2);

  // turn on trigPin for 10 micro sec
  digitalWrite(trigPin, HIGH);
  delay(10);
  digitalWrite(trigPin, LOW);
  
  // output from echopin, returns time in microseconds
  duration= pulseIn(echoPin, HIGH);

  // calculating the distance
  distance = duration * 0.034 / 2;

  //print distance
  Serial.print("Distance: ");
  Serial.println(distance);

  // blink light
  if (distance >= 0 && distance <= 10) {
    digitalWrite(red, HIGH);
    delay(1000);
    digitalWrite(red, LOW);
  }
  else if (distance >= 11 && distance <= 20) {
    digitalWrite(yellow, HIGH);
    delay(1000);
    digitalWrite(yellow, LOW);
  }
  else if (distance >= 21 && distance <= 30) {
    digitalWrite(green, HIGH);
    delay(1000);
    digitalWrite(green, LOW);
  }
  else if (distance > 30) {
    digitalWrite(blue, HIGH);
    delay(1000);
    digitalWrite(blue, LOW);
  }
}















