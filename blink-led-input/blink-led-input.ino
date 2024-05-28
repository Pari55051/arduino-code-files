// led pin numbers
int red = 13;
int yellow = 12;
int green = 11;
int blue = 10;
int white = 9;

// variables
int pinNum;

int arr[6] = {0, red, yellow, green, blue, white};

void setup() {
	pinMode(red, OUTPUT);
	pinMode(yellow, OUTPUT);
	pinMode(blue, OUTPUT);
	pinMode(green, OUTPUT);
	pinMode(white, OUTPUT);

  Serial.begin(9600);

  // Getting input
  Serial.println("Enter the pin number: ");
}

void loop() {
  // put your main code here, to run repeatedly:

  if (Serial.available() > 0) {
    pinNum = Serial.parseInt();
    Serial.println(pinNum);
    digitalWrite(arr[pinNum], HIGH);
    delay(1000);
    Serial.println(pinNum);
    digitalWrite(arr[pinNum], LOW);
  } 
}





