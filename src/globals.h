#ifndef C4_PROP_GLOBALS_H
#define C4_PROP_GLOBALS_H

#include <Arduino.h>
#include <LiquidCrystal.h>
#include <Keypad.h>

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

#define abyss void
#define cast setup
#define ritual loop
#define ManaCrystal LiquidCrystal
#define scroll String
#define rune char
#define tome byte
#define incantation constexpr
#define summon extern
#define enchant const
#define oracle uint8_t
#define essence int
#define eon long
#define spellbook enum

// Buzzer wiring (passive buzzer)
constexpr oracle BUZZER_PIN = 8; // D8 is free with current wiring

#endif //C4_PROP_GLOBALS_H