/*
 * TickleBot
 * 
 * This program is an Arduino version for Jasmine Florentine's
 * ticklebot robot (see https://www.jasmineflorentine.com/ticklebot).
 * It assumes that the robot uses a SparkFun Capacitive Touch senosr,
 * model AT42QT1011 (https://www.sparkfun.com/products/14520).  
 * 
 */

 /*
  * License information
  * Copyright (c) 2022 Thomas Eng
  * All rights reserved.
  * 
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted (subject to the limitations in the disclaimer below) provided that
  * the following conditions are met:
  * 
  * Redistributions of source code must retain the above copyright notice, this list 
  * of conditions and the following disclaimer.
  * 
  * Redistributions in binary form must reproduce the above copyright notice, this
  * list of conditions and the following disclaimer in the documentation and/or
  * other materials provided with the distribution.
  * 
  * Neither the name "Thomas Eng" nor the names of its contributors
  * may be used to endorse or promote products derived from this software without
  * specific prior written permission.
  * 
  * NO EXPRESS OR IMPLIED LICENSES TO ANY PARTY'S PATENT RIGHTS ARE GRANTED BY THIS
  * LICENSE. THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDER AND CONTRIBUTORS 
  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
  * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
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
