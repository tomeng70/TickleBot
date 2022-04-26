/*
 * TickleBot
 * 
 * This program is an Arduino version for Jasmine Florentine's
 * ticklebot robot (see https://www.jasmineflorentine.com/ticklebot).
 * It assumes that the robot uses a SparkFun Capacitive Touch senosr,
 * model AT42QT1011 (https://www.sparkfun.com/products/14520).  
 * 
 */

// The ticklebot has two servos to control the motion of the arms.
#include <Servo.h>
Servo leftArm;
Servo rightArm;

// Change the following limits to match the limits of the servos
// on your ticklebot.
#define LEFT_MIN 45     // degrees
#define LEFT_MAX 135    // degrees
#define RIGHT_MIN 135   // degrees
#define RIGHT_MAX 45    // degrees

// change the following #define statements to match the pins in your setup.
#define LEFT_PIN 6
#define RIGHT_PIN 5
#define TOUCH_PIN 9

// pause period.
#define PAUSE 250       // msec

void setup() {
  // initialize serial connection (in case user wants to debug system).
  Serial.begin(9600);

  // initialize servos.
  leftArm.attach(LEFT_PIN);
  rightArm.attach(RIGHT_PIN);
  leftArm.write(LEFT_MIN);
  rightArm.write(RIGHT_MAX);

  // the SparkFun capacitive touch sensor returns HIGH if it detects a touch.
  // it returns LOW otherwise.
  pinMode(TOUCH_PIN, INPUT);

  // let user know that system is ready.
  Serial.println("Ticklebot has been initialized.");
}

void loop() {
  // is the touch sensor detecting a touch?
  if (digitalRead(TOUCH_PIN)) {
    Serial.println("tickled...");
    
    // move the arms one way.
    leftArm.write(LEFT_MAX);
    rightArm.write(RIGHT_MIN);
    delay(PAUSE);

    // move the arms the other way.
    leftArm.write(LEFT_MIN);
    rightArm.write(RIGHT_MAX);
    delay(PAUSE);
  } else {
    // pause a moment before next iteration.
    delay(PAUSE);
  }
}
