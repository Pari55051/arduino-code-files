#include <DHT11.h>

int red = 8;
int yellow = 9;
int green = 10;
int blue = 11;
int white = 12;

DHT11 dht11(3);

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
  // read ldr data
  int ldrData = analogRead(A0);
  Serial.print(ldrData);
  Serial.print(",");
  // delay(1);

  // map to another range
  int x = map(ldrData, 0,1023,0,255);
  
  for (int i = 0; i < 6; i++) {
    analogWrite(arr[i], x);
  }

  // read dht data
  int temperature = 0;
  int humidity = 0;

  temperature = dht11.readTemperature();
  humidity = dht11.readHumidity();

  if (temperature == 253) {
    Serial.print(0);
  } 
  else {
    Serial.print(temperature);
  }
  Serial.print(",");
  Serial.println(humidity);
  delay(10000);
}








