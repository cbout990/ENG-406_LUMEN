/*
Test sketch to determine if one motor connected to a L298N motor controller will work with an Arduino UNO
*/

int IN1 = 9;
int IN2 = 8;
int ENA = 10;

void setup() {
  // put your setup code here, to run once:
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);
  Serial.begin(9600);
  Serial.println("Enter a number between 0-255 to control the motor speed");
}

int speed = 255;

void loop() {
  // put your main code here, to run repeatedly:
  getSpeed();
  forward(speed);
  delay(2000);
  stop();
  delay(500);
  backward(speed);
  delay(2000);
  stop();
  delay(500);
}

void forward(int speed) {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, speed);
}

void backward(int speed) {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, speed);
}

void stop() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}

void getSpeed() {
  if (Serial.available() > 0) {
    int data = Serial.parseInt();
    if (data >= 0 && data < 256) {
      speed = data;
      Serial.print("Speed: ");
      Serial.println(speed);
    }
    else {
      Serial.println("Please enter a valid speed");
    }
  }
}
