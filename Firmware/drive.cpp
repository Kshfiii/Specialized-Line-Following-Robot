#include "drive.h"
#include "config.h"

static void setMotor(uint8_t in1, uint8_t in2, uint8_t pwm, int spd) {
    if (spd > 0) {
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
    } else if (spd < 0) {
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        spd = -spd;
    } else {
        digitalWrite(in1, LOW);
        digitalWrite(in2, LOW);
    }
    analogWrite(pwm, constrain(spd, 0, 255));
}

void driveInit() {
    pinMode(DRV_STBY, OUTPUT);
    pinMode(L_IN1, OUTPUT); pinMode(L_IN2, OUTPUT); pinMode(L_PWM, OUTPUT);
    pinMode(R_IN1, OUTPUT); pinMode(R_IN2, OUTPUT); pinMode(R_PWM, OUTPUT);
    digitalWrite(DRV_STBY, HIGH);
    driveStop();
}

void driveSetLeft(int spd)  { setMotor(L_IN1, L_IN2, L_PWM, spd); }
void driveSetRight(int spd) { setMotor(R_IN1, R_IN2, R_PWM, spd); }

void driveStop() {
    driveSetLeft(0);
    driveSetRight(0);
}

void driveFwd(int spd) {
    driveSetLeft(spd);
    driveSetRight(spd);
}

void driveRev(int spd) {
    driveSetLeft(-spd);
    driveSetRight(-spd);
}

void driveTurnLeft(int spd) {
    driveSetLeft(-spd);
    driveSetRight(spd);
}

void driveTurnRight(int spd) {
    driveSetLeft(spd);
    driveSetRight(-spd);
}

void driveNudgeLeft() {
    driveSetLeft(-NUDGE_SPEED);
    driveSetRight(NUDGE_SPEED);
    delay(NUDGE_MS);
    driveStop();
    delay(NUDGE_SETTLE);
}

void driveNudgeRight() {
    driveSetLeft(NUDGE_SPEED);
    driveSetRight(-NUDGE_SPEED);
    delay(NUDGE_MS);
    driveStop();
    delay(NUDGE_SETTLE);
}

void driveNudgeBack() {
    driveRev(NUDGE_SPEED);
    delay(NUDGE_MS);
    driveStop();
    delay(NUDGE_SETTLE);
}
