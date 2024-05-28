int red = 8;
int yellow = 9;
int green = 10;
int blue = 11;
int white = 12;

int arr[5] = {red, yellow, green, blue, white};

void setup() {
	pinMode(red, OUTPUT);
	pinMode(yellow, OUTPUT);
	pinMode(blue, OUTPUT);
	pinMode(green, OUTPUT);
	pinMode(white, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorValue = analogRead(A0);
  Serial.println(sensorValue);
  delay(1);

  // map to another range
  int x = map(sensorValue, 0,1023,0,255);
  
  for (int i = 0; i < 6; i++) {
    analogWrite(arr[i], x);
  }
}
