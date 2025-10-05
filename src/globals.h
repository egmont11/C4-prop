#ifndef C4_PROP_GLOBALS_H
#define C4_PROP_GLOBALS_H

#include <Arduino.h>
#include <LiquidCrystal.h>
#include <Keypad.h>

// Buzzer wiring (passive buzzer)
constexpr uint8_t BUZZER_PIN = 8; // D8 is free with current wiring

// Forward declaration of your enum
enum State {
    SetPassword,
    SetTimer,
    Ticking,
    Defused,
    Explosion
};

// Extern declarations (these are defined in main.cpp)
extern LiquidCrystal lcd;
extern Keypad keypad;
extern State state;
extern String password;
extern int minutes;
extern long seconds;
extern String passwordOnDefusal;

#endif //C4_PROP_GLOBALS_H