#pragma once
#include <Arduino.h>

void navInit();
void navFollowLine();
void navStop();
void navResetOdometry();
bool navReachedDistance(long targetCm);
bool navRackInRange();
void navApproachRack();
