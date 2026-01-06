/*
  Mobile Manipulation Robot - Full Arduino Sketch
  Controls:
    - 6-DOF Robotic Arm (MG996R/SG90)
    - Mecanum Wheels (L298N/L293D Motor Drivers)
  Author: Hatem Safwat Mohamed
*/

#include <Servo.h>

// --------------------- Arm Servo Pins ---------------------
#define SERVO1_PIN 2
#define SERVO2_PIN 3
#define SERVO3_PIN 4
#define SERVO4_PIN 5
#define SERVO5_PIN 6
#define SERVO6_PIN 7

Servo servo1, servo2, servo3, servo4, servo5, servo6;

// --------------------- Mecanum Motor Pins ---------------------
// Motor A (Front Left)
#define M1_EN 9
#define M1_IN1 22
#define M1_IN2 23
// Motor B (Front Right)
#define M2_EN 10
#define M2_IN1 24
#define M2_IN2 25
// Motor C (Rear Left)
#define M3_EN 11
#define M3_IN1 26
#define M3_IN2 27
// Motor D (Rear Right)
#define M4_EN 12
#define M4_IN1 28
#define M4_IN2 29

// --------------------- PID Placeholders for Arm ---------------------
float Kp = 1.0, Ki = 0.0, Kd = 0.0;  // PID constants
float setPoint[6] = {90, 90, 90, 90, 90, 90}; // Default home position
float currentPos[6] = {90, 90, 90, 90, 90, 90};
float error[6], prevError[6], integral[6];

// --------------------- Setup ---------------------
void setup() {
  Serial.begin(9600);

  // Attach all 6 arm servos
  servo1.attach(SERVO1_PIN);
  servo2.attach(SERVO2_PIN);
  servo3.attach(SERVO3_PIN);
  servo4.attach(SERVO4_PIN);
  servo5.attach(SERVO5_PIN);
  servo6.attach(SERVO6_PIN);

  // Initialize servos to home positions
  for (int i = 0; i < 6; i++) currentPos[i] = setPoint[i];
  writeServos();

  // Setup Mecanum motor pins
  pinMode(M1_EN, OUTPUT); pinMode(M1_IN1, OUTPUT); pinMode(M1_IN2, OUTPUT);
  pinMode(M2_EN, OUTPUT); pinMode(M2_IN1, OUTPUT); pinMode(M2_IN2, OUTPUT);
  pinMode(M3_EN, OUTPUT); pinMode(M3_IN1, OUTPUT); pinMode(M3_IN2, OUTPUT);
  pinMode(M4_EN, OUTPUT); pinMode(M4_IN1, OUTPUT); pinMode(M4_IN2, OUTPUT);

  Serial.println("Robot initialized.");
}

// --------------------- Loop ---------------------
void loop() {
  // ------------------ Arm Movement Example ------------------
  float targets1[6] = {120, 60, 90, 45, 135, 90};
  float targets2[6] = {90, 120, 60, 90, 45, 135};

  Serial.println("Moving arm to position 1...");
  moveArmToTarget(targets1);
  delay(2000);

  Serial.println("Moving arm to position 2...");
  moveArmToTarget(targets2);
  delay(2000);

  Serial.println("Returning arm to home...");
  moveArmToTarget(setPoint);
  delay(2000);

  // ------------------ Mecanum Base Example ------------------
  Serial.println("Driving forward...");
  driveMecanum(150, 0, 0); // Forward speed
  delay(2000);

  Serial.println("Strafing right...");
  driveMecanum(0, 150, 0); // Strafe right
  delay(2000);

  Serial.println("Rotating clockwise...");
  driveMecanum(0, 0, 100); // Rotate
  delay(2000);

  Serial.println("Stopping...");
  driveMecanum(0, 0, 0); // Stop
  delay(2000);
}

// --------------------- Arm Control Functions ---------------------
void moveArmToTarget(float target[6]) {
  bool moving = true;
  while (moving) {
    moving = false; // Assume all joints reached target
    for (int i = 0; i < 6; i++) {
      error[i] = target[i] - currentPos[i];
      integral[i] += error[i];
      float derivative = error[i] - prevError[i];
      float output = Kp * error[i] + Ki * integral[i] + Kd * derivative;

      if (abs(error[i]) > 0.5) {
        moving = true;
        currentPos[i] += constrain(output, -2.0, 2.0); // Max 2 degrees per loop
      }
      prevError[i] = error[i];
    }
    writeServos();
    delay(20); // Small delay for smooth motion
  }
}

void writeServos() {
  servo1.write(currentPos[0]);
  servo2.write(currentPos[1]);
  servo3.write(currentPos[2]);
  servo4.write(currentPos[3]);
  servo5.write(currentPos[4]);
  servo6.write(currentPos[5]);
}

// --------------------- Mecanum Drive Functions ---------------------
void driveMecanum(int vx, int vy, int omega) {
  int m1 = vx - vy - omega; // Front Left
  int m2 = vx + vy + omega; // Front Right
  int m3 = vx + vy - omega; // Rear Left
  int m4 = vx - vy + omega; // Rear Right

  setMotor(M1_EN, M1_IN1, M1_IN2, m1);
  setMotor(M2_EN, M2_IN1, M2_IN2, m2);
  setMotor(M3_EN, M3_IN1, M3_IN2, m3);
  setMotor(M4_EN, M4_IN1, M4_IN2, m4);
}

void setMotor(int en, int in1, int in2, int speed) {
  if (speed >= 0) {
    analogWrite(en, constrain(speed, 0, 255));
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
  } else {
    analogWrite(en, constrain(-speed, 0, 255));
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
  }
}

