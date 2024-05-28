const int numLeds = 5; // maximum number of LEDs
int ledPins[numLeds] = {13, 12, 14, 27, 26}; // LED pins

void setup() {
  Serial.begin(9600);

  //setup for PinMode
  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
  }

  Serial.println("Enter the values (comma or space separated): ");
}

void loop() {
  // Serial.println("Enter the values (comma or space separated): ");
  String inputString = Serial.readString();  //take input
  int ledNumbers[numLeds];    // declare the inputs storing array
  int numLedsToGlow = 0;      //

  // parse the input string into an array of LED numbers
  int start = 0;
  for (int i = 0; i < inputString.length(); i++) {

    if (inputString[i] == ',' || i == inputString.length() - 1 || inputString[i] == ' ') {
      String ledNumberStr = inputString.substring(start, i);
      ledNumbers[numLedsToGlow++] = ledNumberStr.toInt();
      start = i + 1;
    }

  }

  // glow the LEDs for 1 second
  for (int i = 0; i < numLedsToGlow; i++) {
    digitalWrite(ledPins[ledNumbers[i] - 1], HIGH);
    delay(1000);
    digitalWrite(ledPins[ledNumbers[i] - 1], LOW);
  }

}
