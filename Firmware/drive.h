#pragma once
#include <Arduino.h>

void driveInit();
void driveSetLeft(int spd);
void driveSetRight(int spd);
void driveStop();
void driveFwd(int spd);
void driveRev(int spd);
void driveTurnLeft(int spd);
void driveTurnRight(int spd);
void driveNudgeLeft();
void driveNudgeRight();
void driveNudgeBack();
