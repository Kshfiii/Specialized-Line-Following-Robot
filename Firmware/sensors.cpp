#include "sensors.h"
#include "config.h"
#include <Wire.h>
#include <Adafruit_TCS34725.h>

static Adafruit_TCS34725 tcs = Adafruit_TCS34725(
    TCS34725_INTEGRATIONTIME_50MS,
    TCS34725_GAIN_4X
);

volatile long encL = 0;
volatile long encR = 0;

static void isrEncL() { encL++; }
static void isrEncR() { encR++; }

void sensorsInit() {
    for (int i = 0; i < IR_COUNT; i++) {
        pinMode(IR_PINS[i], INPUT);
    }
    pinMode(SONAR_TRIG, OUTPUT);
    pinMode(SONAR_ECHO, INPUT);
    digitalWrite(SONAR_TRIG, LOW);

    pinMode(ENC_L, INPUT_PULLUP);
    pinMode(ENC_R, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(ENC_L), isrEncL, RISING);
    attachInterrupt(digitalPinToInterrupt(ENC_R), isrEncR, RISING);
}

void colorInit() {
    Wire.begin();
    if (!tcs.begin()) {
        pinMode(STATUS_LED, OUTPUT);
        while (1) {
            digitalWrite(STATUS_LED, !digitalRead(STATUS_LED));
            delay(150);
        }
    }
}

void irRead(bool *out) {
    for (int i = 0; i < IR_COUNT; i++) {
        out[i] = (digitalRead(IR_PINS[i]) == HIGH);
    }
}

int irError() {
    bool s[IR_COUNT];
    irRead(s);
    static const int W[IR_COUNT] = { -5, -3, -1, 1, 3, 5 };
    int sum = 0, cnt = 0;
    for (int i = 0; i < IR_COUNT; i++) {
        if (s[i]) { sum += W[i]; cnt++; }
    }
    return cnt ? sum / cnt : 0;
}

bool irJunction() {
    bool s[IR_COUNT];
    irRead(s);
    int cnt = 0;
    for (int i = 0; i < IR_COUNT; i++) if (s[i]) cnt++;
    return cnt >= 4;
}

bool irAllBlack() {
    bool s[IR_COUNT];
    irRead(s);
    for (int i = 0; i < IR_COUNT; i++) if (!s[i]) return false;
    return true;
}

float sonarCm() {
    digitalWrite(SONAR_TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(SONAR_TRIG, LOW);
    long dur = pulseIn(SONAR_ECHO, HIGH, 25000UL);
    return dur ? dur / 58.0f : 999.0f;
}

void encoderReset() {
    noInterrupts();
    encL = 0;
    encR = 0;
    interrupts();
}

long encoderAvg() {
    noInterrupts();
    long l = encL, r = encR;
    interrupts();
    return (l + r) / 2;
}

SlotColor colorRead() {
    int blue = 0, red = 0;
    for (int i = 0; i < 5; i++) {
        uint16_t r, g, b, c;
        tcs.getRawData(&r, &g, &b, &c);
        if (c == 0) { delay(60); continue; }
        float rn = (float)r / c;
        float bn = (float)b / c;
        if      (bn > rn * 1.4f) blue++;
        else if (rn > bn * 1.4f) red++;
        delay(60);
    }
    if (blue >= 3) return COLOR_BLUE;
    if (red  >= 3) return COLOR_RED;
    return COLOR_UNKNOWN;
}
