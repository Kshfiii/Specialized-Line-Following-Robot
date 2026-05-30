#pragma once
#include <Arduino.h>

// ── drive TB6612FNG ─────────────────────────────────────────────────────────
// left motors (FL + BL wired in parallel on channel A)
#define DRV_STBY    PA6
#define L_IN1       PA0
#define L_IN2       PA1
#define L_PWM       PA2
// right motors (FR + BR wired in parallel on channel B)
#define R_IN1       PA3
#define R_IN2       PA4
#define R_PWM       PA5

// ── mechanism TB6612FNG ─────────────────────────────────────────────────────
#define MCH_STBY    PA7
#define LFT_IN1     PB0
#define LFT_IN2     PB1
#define LFT_PWM     PB3
#define CNV_IN1     PB4
#define CNV_IN2     PB5
#define CNV_PWM     PB8

// ── servo, encoders, sonar ──────────────────────────────────────────────────
#define SERVO_PIN   PB9
#define ENC_L       PB10
#define ENC_R       PB11
#define SONAR_TRIG  PB12
#define SONAR_ECHO  PB13

// ── IR array (6 sensors, left → right) ─────────────────────────────────────
#define IR_COUNT 6
const uint8_t IR_PINS[IR_COUNT] = { PA8, PA11, PA12, PB14, PB15, PA15 };
// IR_PINS[i] == HIGH  →  sensor over black line (adjust polarity if inverted)

// ── TCS34725 on Wire (I2C1: PB6=SCL  PB7=SDA) ──────────────────────────────

// ── misc ────────────────────────────────────────────────────────────────────
#define START_BTN   PB2
#define STATUS_LED  PC13   // active LOW on Black Pill

// ── drive tuning ────────────────────────────────────────────────────────────
#define DRIVE_BASE   155
#define DRIVE_MAX    220
#define TURN_SPEED   130
#define RAMP_SPEED   DRIVE_MAX

// ── PID ─────────────────────────────────────────────────────────────────────
#define KP  0.40f
#define KI  0.00f
#define KD  0.20f

// ── encoder odometry ────────────────────────────────────────────────────────
#define TICKS_PER_CM   21      // calibrate on actual surface

// ── sonar thresholds (cm) ───────────────────────────────────────────────────
#define SONAR_RACK_CM   8
#define SONAR_WALL_CM   12

// ── distances from start to each target (cm) ────────────────────────────────
#define DIST_TO_S1      60
#define DIST_S1_TO_S2   105
#define DIST_S2_TO_RAMP 140

// ── lift timing ─────────────────────────────────────────────────────────────
#define LIFT_SPEED      180
#define LIFT_RAISE_MS   1100   // time to reach upper row from collapsed
#define LIFT_LOWER_MS   1100

// ── conveyor ────────────────────────────────────────────────────────────────
#define CONV_SPEED      210
#define CONV_EJECT_MS   750

// ── servo sweep angles ───────────────────────────────────────────────────────
#define SERVO_LEFT   35
#define SERVO_RIGHT  145
#define SERVO_MID    90

// ── slot lateral alignment ───────────────────────────────────────────────────
// brief timed nudge to align conveyor exit with left or right slot
#define NUDGE_SPEED    100
#define NUDGE_MS       160     // tune until conveyor lines up with slot center
#define NUDGE_SETTLE   80
