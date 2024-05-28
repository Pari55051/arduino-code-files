void setup() {
  // put your setup code here, to run once:
  pinMode(12, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int value = digitalRead(12); // also analogRead(12)
  Serial.println(value);
}

// read values from 