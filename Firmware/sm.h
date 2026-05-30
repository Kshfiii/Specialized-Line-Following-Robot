#pragma once
#include <Arduino.h>

enum RobotState {
    ST_IDLE,
    ST_TO_S1,
    ST_SERVICE_S1,
    ST_TO_S2,
    ST_SERVICE_S2,
    ST_TO_RAMP,
    ST_CLIMB,
    ST_SERVICE_S3,
    ST_PARK,
    ST_DONE
};

void smInit();
void smStart();
void smTick();
RobotState smGetState();
int smPalletsLeft();
