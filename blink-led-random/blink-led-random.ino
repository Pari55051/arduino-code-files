int red = 13;
int yellow = 12;
int green = 14;
int blue = 27;
int white = 26;

int arr[5] = {red, yellow, green, blue, white};

void setup() {
	pinMode(red, OUTPUT);
	pinMode(yellow, OUTPUT);
	pinMode(blue, OUTPUT);
	pinMode(green, OUTPUT);
	pinMode(white, OUTPUT);
}

void loop() {
	int i = random(0,5);
	digitalWrite(arr[i], HIGH);
	delay(100);
	digitalWrite(arr[i], LOW);
}
