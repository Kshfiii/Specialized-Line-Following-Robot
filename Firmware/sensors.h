#pragma once
#include <Arduino.h>

void sensorsInit();
void colorInit();

// ── IR array ─────────────────────────────────────────────────────────────────
void irRead(bool *out);
int  irError();
bool irJunction();
bool irAllBlack();

// ── sonar ────────────────────────────────────────────────────────────────────
float sonarCm();

// ── color ────────────────────────────────────────────────────────────────────
enum SlotColor { COLOR_BLUE, COLOR_RED, COLOR_UNKNOWN };
SlotColor colorRead();

// ── encoders ─────────────────────────────────────────────────────────────────
extern volatile long encL;
extern volatile long encR;
void  encoderReset();
long  encoderAvg();
