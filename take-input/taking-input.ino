int xInteger;
float yFloat;
String zString; 


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Enter yout input here: ");
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    xInteger = Serial.parseInt();  // can also use []Serial.parseFloat() or []Serial.readString() ++ suitable variable
    Serial.print("You entered: ");
    Serial.println(xInteger);     // change variable according to the func
    while(1) {}  // prevent infinte loop because always true and no code in body /// does not keep asking the input repeatedly
  }
}
