#define enA 9  // Enable pin for motor driver
#define in1 4  // Input pin 1 for motor driver
#define in2 5  // Input pin 2 for motor driver

void setup() {
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  Serial.begin(9600);
  Serial.println("Enter motor speed: [fast, slow, very fast, very slow");
}

void loop() {
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    input.trim();

    if (input == "fast") {
      setMotorSpeed(200); // 200 RPM
    } else if (input == "slow") {
      setMotorSpeed(100); // 100 RPM
    } else if (input == "very fast") {
      setMotorSpeed(250); // 250 RPM
    } else if (input == "very slow") {
      setMotorSpeed(50); // 50 RPM
    } else {
      Serial.println("Invalid input. Please enter 'fast', 'slow', 'very fast', or 'very slow'.");
    }
  }
}

void setMotorSpeed(int rpm) {
  int pwmValue = map(rpm, 0, 300, 0, 255);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, pwmValue);
}