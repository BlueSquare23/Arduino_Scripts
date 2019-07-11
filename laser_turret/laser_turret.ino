/*
  Laser Turret System

  This circit reads from a joy stick (analog in) and uses that input to control the 
  direction of a laser turret, constructed of two hot glued together servo motors.
  
 */
#include <Servo.h>

Servo myservoX;  // create servo object to control a servo
Servo myservoY;  // create servo object to control a servo
 
const int analogInPinX = A0; // Analog input pin that the joystick is attached to
const int analogInPinY = A1; // Analog input pin that the joystick is attached to

int sensorValueX = 0;
int sensorValueY = 0;

int outputValueX = 0;
int outputValueY = 0;

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  
  myservoX.attach(9);  // attaches the servo on pin 9 to the servo object
  myservoY.attach(11);  // attaches the servo on pin 11 to the servo object

}

void loop() {
  // read the analog in values:
  sensorValueX = analogRead(analogInPinX);
  sensorValueY = analogRead(analogInPinY);

  // map it to the range of the analog out:
  outputValueX = map(sensorValueX, 0, 1023, 0, 180);
  outputValueY = map(sensorValueY, 0, 1023, 0, 180);

  //Servo Control
  myservoX.write(outputValueX);                  // sets the servo position according to the scaled value
  delay(15);                                     // waits for the servo to get there

  myservoY.write(outputValueY);                  // sets the servo position according to the scaled value
  delay(15);                 
   
  // print the results to the Serial Monitor:
  Serial.print("sensor = ");
  Serial.println(sensorValueX);
  Serial.println(sensorValueY);

  
  // wait 2 milliseconds before the next loop for the analog-to-digital
  // converter to settle after the last reading:
  delay(2);
}
