#include "nav.h"
#include "config.h"
#include "drive.h"
#include "sensors.h"

static float integral = 0;
static int   lastErr  = 0;

void navInit() {
    integral = 0;
    lastErr  = 0;
}

void navFollowLine() {
    int err = irError();
    integral += err;
    integral  = constrain(integral, -60.0f, 60.0f);
    int deriv = err - lastErr;
    lastErr   = err;

    float correction = KP * err + KI * integral + KD * (float)deriv;
    int l = constrain((int)(DRIVE_BASE + correction), -DRIVE_MAX, DRIVE_MAX);
    int r = constrain((int)(DRIVE_BASE - correction), -DRIVE_MAX, DRIVE_MAX);
    driveSetLeft(l);
    driveSetRight(r);
}

void navStop() {
    driveStop();
    integral = 0;
    lastErr  = 0;
}

void navResetOdometry() {
    encoderReset();
    integral = 0;
    lastErr  = 0;
}

bool navReachedDistance(long targetCm) {
    return encoderAvg() >= (long)(targetCm * TICKS_PER_CM);
}

bool navRackInRange() {
    return sonarCm() <= (float)(SONAR_RACK_CM + 2);
}

void navApproachRack() {
    while (sonarCm() > SONAR_RACK_CM) {
        navFollowLine();
        delay(5);
    }
    navStop();
}
