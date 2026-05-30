#include "lift.h"
#include "config.h"
#include <Servo.h>

static Servo sweepServo;
static uint8_t liftPos = 0;   // 0=low  1=high

static void liftMotor(int spd) {
    if (spd > 0) {
        digitalWrite(LFT_IN1, HIGH);
        digitalWrite(LFT_IN2, LOW);
    } else if (spd < 0) {
        digitalWrite(LFT_IN1, LOW);
        digitalWrite(LFT_IN2, HIGH);
        spd = -spd;
    } else {
        digitalWrite(LFT_IN1, LOW);
        digitalWrite(LFT_IN2, LOW);
    }
    analogWrite(LFT_PWM, constrain(spd, 0, 255));
}

static void convMotor(int spd) {
    if (spd > 0) {
        digitalWrite(CNV_IN1, HIGH);
        digitalWrite(CNV_IN2, LOW);
    } else {
        digitalWrite(CNV_IN1, LOW);
        digitalWrite(CNV_IN2, LOW);
    }
    analogWrite(CNV_PWM, constrain(spd, 0, 255));
}

void liftInit() {
    pinMode(MCH_STBY, OUTPUT);
    pinMode(LFT_IN1, OUTPUT); pinMode(LFT_IN2, OUTPUT); pinMode(LFT_PWM, OUTPUT);
    pinMode(CNV_IN1, OUTPUT); pinMode(CNV_IN2, OUTPUT); pinMode(CNV_PWM, OUTPUT);
    digitalWrite(MCH_STBY, HIGH);
    sweepServo.attach(SERVO_PIN);
    sweepServo.write(SERVO_MID);
    liftPos = 0;
}

void liftGoLow() {
    if (liftPos == 0) return;
    liftMotor(-LIFT_SPEED);
    delay(LIFT_LOWER_MS);
    liftMotor(0);
    liftPos = 0;
}

void liftGoHigh() {
    if (liftPos == 1) return;
    liftMotor(LIFT_SPEED);
    delay(LIFT_RAISE_MS);
    liftMotor(0);
    liftPos = 1;
}

void conveyorEject() {
    convMotor(CONV_SPEED);
    delay(CONV_EJECT_MS);
    convMotor(0);
}

void servoLeft() {
    sweepServo.write(SERVO_LEFT);
    delay(300);
}

void servoRight() {
    sweepServo.write(SERVO_RIGHT);
    delay(300);
}

void servoCenter() {
    sweepServo.write(SERVO_MID);
    delay(200);
}
