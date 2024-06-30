void setup() {
  // put your setup code here, to run once:
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  // pinMode(11, OUTPUT);
  // pinMode(12, OUTPUT);

  Serial.begin(9600);
  Serial.println("Enter the pin number: ");

}

int pumpGroup;

void loop() {
  // digitalWrite(10,HIGH);
  // delay(5000);
  // digitalWrite(10, LOW);
  // delay(1000);

  // digitalWrite(9, HIGH);
  // delay(5000);
  // digitalWrite(9, LOW);
  // delay(1000);

  if (Serial.available() > 1) {
    pumpGroup = Serial.parseInt();
    Serial.println(pumpGroup);

    if (pumpGroup == 9) {
      digitalWrite(9, HIGH);
      // digitalWrite(11, HIGH);
      // delay(10000);
      digitalWrite(10, LOW);
      // digitalWrite(12, LOW);
      // delay(1000);
    } else if (pumpGroup == 10) {
      digitalWrite(10,HIGH);
      // digitalWrite(12,HIGH);
      // delay(10000);
      digitalWrite(9, LOW);
      // digitalWrite(11, LOW);
      // delay(1000);
    } else if (pumpGroup == 100) {
      digitalWrite(10,HIGH);
      // digitalWrite(12,HIGH);
      // delay(10000);
      digitalWrite(9, HIGH);
      // digitalWrite(11, LOW);
      // delay(1000);
    } else {
      digitalWrite(10, LOW);
      // digitalWrite(12, LOW);
      digitalWrite(9, LOW);
      // digitalWrite(11, LOW);
    }
  }
  
}


/* ============== PSEUDO CODE ============= */
/*
 if mood is happy:
    run groups [red / blue]
 if mood is sad:
    run groups [ green ]
 if mood is angry:
    run groups [red / blue / green]
 if mood is neutral:
    run groups [  ]
*/

// GROUPS DESC
/* red - 2 motors
   blue - 2 motors
   green - 1 motor
*/