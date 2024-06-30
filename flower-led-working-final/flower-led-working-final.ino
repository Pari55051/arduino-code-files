#include <Servo.h>
#include <FastLED.h>

Servo myservo1;
int isBloom;
int currentPos = 45;  // initial position of the servo

#define NUM_LEDS 1
#define DATA_PIN 7
#define CLOCK_PIN 13

CRGB leds[NUM_LEDS];


void setup() {
  // put your setup code here, to run once:
  myservo1.attach(8);

  Serial.begin(9600);
  Serial.println("Enter state: (y:2 / n:1)");
  myservo1.write(currentPos);  // set the initial position

  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);  // GRB ordering is assumed

}

void loop() {
  if (Serial.available() > 1) {
    isBloom = Serial.parseInt();
    Serial.println(isBloom);

    if (isBloom == 1 && currentPos < 180) {
      for (int pos = currentPos; pos <= 180; pos++) {
        myservo1.write(pos);
        delay(10);
      }
      currentPos = 180;  // update the current position
        fill_solid(leds,1,CRGB::Red);
        // fill_solid(leds+38,76,strtol("0x0000FF",NULL,0));
        FastLED.show();
    } else if (isBloom == 2 && currentPos > 45) {
      for (int pos = currentPos; pos >= 45; pos--) {
        myservo1.write(pos);
        delay(10);
      }
      currentPos = 45;  // update the current position
      fill_solid(leds,1,CRGB::Red);
      // fill_solid(leds+38,76,strtol("0x0000FF",NULL,0));
      FastLED.show();
    } else {
      Serial.println("Invalid input or already in that state!");
    }
  }
}