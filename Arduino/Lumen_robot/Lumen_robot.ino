 //ENG406 Functional Prototype Arduino Sketch - by Sam Caasi

#include "motors.h" // motor setup
#include "ultrasonic.h" // ultrasonic setup
#include <MinimalUltrasonic.h>


// Individual motor scale down factors from 1(normal)-10(lowest)
int s_FL = 3;
int s_FR = 1;
int s_RL = 3;
int s_RR = 1;

//demo values to change (these will not be the correct timings)

//Motor speed can be 0-255
int DRIVE_SPEED = 150;

//distance #1 travel time
unsigned long FULL_DISTANCE_TIME = 1000;

//distance #2 travel time
unsigned long HALF_DISTANCE_TIME;

//180 degree turn time
unsigned long TURN_180_TIME = 500;

//pause time
unsigned long PAUSE_TIME = 1000;




void setup() {

  //front left
  pinMode(FL_EN, OUTPUT);
  pinMode(FL_IN1, OUTPUT);
  pinMode(FL_IN2, OUTPUT);

  //front right
  pinMode(FR_EN, OUTPUT);
  pinMode(FR_IN3, OUTPUT);
  pinMode(FR_IN4, OUTPUT);

  //rear left
  pinMode(RL_EN, OUTPUT);
  pinMode(RL_IN1, OUTPUT);
  pinMode(RL_IN2, OUTPUT);

  //rear right
  pinMode(RR_EN, OUTPUT);
  pinMode(RR_IN3, OUTPUT);
  pinMode(RR_IN4, OUTPUT);

  // setup ultrasonic sensors
  ultrasonic_setup();

  //calculate distance #2 from distance #1 (mostly just for the demo)
  HALF_DISTANCE_TIME = FULL_DISTANCE_TIME / 2;

  // stopRobot();

  delay(1000);
}



//demo instructions

void loop() {
  // ultrasonic test
  float dist1 = front_L.read();
  delay(50);  // Wait between sensors
  
  float dist2 = front_M.read();
  delay(50);
  
  float dist3 = front_R.read();
  delay(50);

  float dist4 = left.read();
  delay(50);

  float dist5 = right.read();
  delay(50);

  float dist6 = back.read();
  delay(50);

/*
//go forward distance #1

  forward(DRIVE_SPEED);
  delay(FULL_DISTANCE_TIME);

  stopRobot();
  delay(PAUSE_TIME);


//turn 180 clockwise

  turnRight(DRIVE_SPEED);
  delay(TURN_180_TIME);

  stopRobot();
  delay(PAUSE_TIME);


//go forward distance #1

  forward(DRIVE_SPEED);
  delay(FULL_DISTANCE_TIME);

  stopRobot();
  delay(PAUSE_TIME);


//go backward distance #2

  backward(DRIVE_SPEED);
  delay(HALF_DISTANCE_TIME);

  stopRobot();
  delay(PAUSE_TIME);


//turn 180 counterclockwise

  turnLeft(DRIVE_SPEED);
  delay(TURN_180_TIME);

  stopRobot();
  delay(PAUSE_TIME);


//go forward distance #2

  forward(DRIVE_SPEED);
  delay(HALF_DISTANCE_TIME);

  stopRobot();

//stop

  while (true) {
    stopRobot();
    delay(1000);
  }
  */
}






//functions to call

//forward
void forward(int speed) {

  digitalWrite(FL_IN1, HIGH);
  digitalWrite(FL_IN2, LOW);

  digitalWrite(FR_IN3, HIGH);
  digitalWrite(FR_IN4, LOW);

  digitalWrite(RL_IN1, HIGH);
  digitalWrite(RL_IN2, LOW);

  digitalWrite(RR_IN3, HIGH);
  digitalWrite(RR_IN4, LOW);

  setSpeed(speed);
}

//backward
void backward(int speed) {

  digitalWrite(FL_IN1, LOW);
  digitalWrite(FL_IN2, HIGH);

  digitalWrite(FR_IN3, LOW);
  digitalWrite(FR_IN4, HIGH);

  digitalWrite(RL_IN1, LOW);
  digitalWrite(RL_IN2, HIGH);

  digitalWrite(RR_IN3, LOW);
  digitalWrite(RR_IN4, HIGH);

  setSpeed(speed);
}

//strafe left
void left(int speed) {

  digitalWrite(FL_IN1, LOW);
  digitalWrite(FL_IN2, HIGH);

  digitalWrite(FR_IN3, HIGH);
  digitalWrite(FR_IN4, LOW);

  digitalWrite(RL_IN1, HIGH);
  digitalWrite(RL_IN2, LOW);

  digitalWrite(RR_IN3, LOW);
  digitalWrite(RR_IN4, HIGH);

  setSpeed(speed);
}

//strafe right
void right(int speed) {

  digitalWrite(FL_IN1, HIGH);
  digitalWrite(FL_IN2, LOW);

  digitalWrite(FR_IN3, LOW);
  digitalWrite(FR_IN4, HIGH);

  digitalWrite(RL_IN1, LOW);
  digitalWrite(RL_IN2, HIGH);

  digitalWrite(RR_IN3, HIGH);
  digitalWrite(RR_IN4, LOW);

  setSpeed(speed);
}

//turn clockwise
void turnRight(int speed) {

  digitalWrite(FL_IN1, HIGH);
  digitalWrite(FL_IN2, LOW);

  digitalWrite(RL_IN1, HIGH);
  digitalWrite(RL_IN2, LOW);

  digitalWrite(FR_IN3, LOW);
  digitalWrite(FR_IN4, HIGH);

  digitalWrite(RR_IN3, LOW);
  digitalWrite(RR_IN4, HIGH);

  setSpeed(speed);
}

//turn counterclockwise
void turnLeft(int speed) {

  digitalWrite(FL_IN1, LOW);
  digitalWrite(FL_IN2, HIGH);

  digitalWrite(RL_IN1, LOW);
  digitalWrite(RL_IN2, HIGH);

  digitalWrite(FR_IN3, HIGH);
  digitalWrite(FR_IN4, LOW);

  digitalWrite(RR_IN3, HIGH);
  digitalWrite(RR_IN4, LOW);

  setSpeed(speed);
}

//set speed from 0-255
void setSpeed(int speed) {

  //make sure speed stays between 0 and 255
  speed = constrain(speed, 0, 255);

  analogWrite(FL_EN, speed);
  analogWrite(FR_EN, speed);
  analogWrite(RL_EN, speed);
  analogWrite(RR_EN, speed);
}

//stop
void stopRobot() {

  digitalWrite(FL_IN1, LOW);
  digitalWrite(FL_IN2, LOW);

  digitalWrite(FR_IN3, LOW);
  digitalWrite(FR_IN4, LOW);

  digitalWrite(RL_IN1, LOW);
  digitalWrite(RL_IN2, LOW);

  digitalWrite(RR_IN3, LOW);
  digitalWrite(RR_IN4, LOW);

  //disable PWM
  analogWrite(FL_EN, 0);
  analogWrite(FR_EN, 0);
  analogWrite(RL_EN, 0);
  analogWrite(RR_EN, 0);
}
