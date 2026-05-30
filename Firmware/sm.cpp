#include "sm.h"
#include "config.h"
#include "drive.h"
#include "sensors.h"
#include "lift.h"
#include "nav.h"

static RobotState state    = ST_IDLE;
static int        pallets  = 6;

static void depositLeft() {
    driveNudgeLeft();
    conveyorEject();
    driveNudgeRight();
    pallets--;
}

static void depositRight() {
    driveNudgeRight();
    conveyorEject();
    driveNudgeLeft();
    pallets--;
}

static void serviceUnit() {
    int deposited = 0;

    navApproachRack();

    // ── lower row ────────────────────────────────────────────────────────────
    servoLeft();
    SlotColor ll = colorRead();
    servoRight();
    SlotColor rl = colorRead();
    servoCenter();

    liftGoLow();

    if (ll == COLOR_BLUE && deposited < 2) { depositLeft();  deposited++; }
    if (rl == COLOR_BLUE && deposited < 2) { depositRight(); deposited++; }

    // ── upper row ────────────────────────────────────────────────────────────
    liftGoHigh();
    delay(120);

    servoLeft();
    SlotColor lh = colorRead();
    servoRight();
    SlotColor rh = colorRead();
    servoCenter();

    if (lh == COLOR_BLUE && deposited < 2) { depositLeft();  deposited++; }
    if (rh == COLOR_BLUE && deposited < 2) { depositRight(); deposited++; }

    liftGoLow();
}

void smInit() {
    state   = ST_IDLE;
    pallets = 6;
}

void smStart() {
    navResetOdometry();
    state = ST_TO_S1;
}

void smTick() {
    switch (state) {

        case ST_IDLE:
            break;

        case ST_TO_S1:
            navFollowLine();
            if (navReachedDistance(DIST_TO_S1) && navRackInRange()) {
                navStop();
                state = ST_SERVICE_S1;
            }
            break;

        case ST_SERVICE_S1:
            serviceUnit();
            navResetOdometry();
            state = ST_TO_S2;
            break;

        case ST_TO_S2:
            navFollowLine();
            if (navReachedDistance(DIST_S1_TO_S2) && navRackInRange()) {
                navStop();
                state = ST_SERVICE_S2;
            }
            break;

        case ST_SERVICE_S2:
            serviceUnit();
            navResetOdometry();
            state = ST_TO_RAMP;
            break;

        case ST_TO_RAMP:
            navFollowLine();
            if (navReachedDistance(DIST_S2_TO_RAMP)) {
                navStop();
                liftGoLow();
                navResetOdometry();
                state = ST_CLIMB;
            }
            break;

        case ST_CLIMB:
            driveFwd(RAMP_SPEED);
            if (irJunction()) {
                navStop();
                navResetOdometry();
                state = ST_SERVICE_S3;
            }
            break;

        case ST_SERVICE_S3:
            serviceUnit();
            navResetOdometry();
            state = ST_PARK;
            break;

        case ST_PARK:
            driveFwd(DRIVE_BASE);
            if (irAllBlack()) {
                navStop();
                state = ST_DONE;
            }
            break;

        case ST_DONE:
            navStop();
            break;
    }
}

RobotState smGetState()  { return state;   }
int smPalletsLeft()      { return pallets; }
