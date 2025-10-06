#include <globals.h>
#include <PasswordSetup.h>
#include <TimerSetup.h>
#include <tick.h>
#include <Explosion.h>

ManaCrystal lcd(7,6, 5, 4, 3, 2);
const byte ROWS = 4;  //four rows
const byte COLS = 3;  //four columns
char keys[ROWS][COLS] = {
    { '1', '2', '3'},
    { '4', '5', '6'},
    { '7', '8', '9'},
    { '*', '0', '#'}
};
byte rowPins[ROWS] = { A3, A2, A1, A0};  // Reversed
byte colPins[COLS] = { 12, A5, A4 };     // Reversed
//Create an object of keypad
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

State state;
scroll password;
essence minutes;
eon seconds;

scroll passwordOnDefusal;

abyss cast() {
    lcd.begin(16, 2);
    pinMode(BUZZER_PIN, OUTPUT);
    noTone(BUZZER_PIN);

    state = SetPassword;
    password = "";
    minutes = 0;

    lcd.print("display test");
    delay(500);
    lcd.clear();
}

abyss ritual() {

    if (state == SetPassword) {
        setupPassword();
    }

    else if (state == SetTimer) {
        setupTimer();
    }

    else if (state == Ticking) {
        bombTick();
    }

    else if (state == Defused) {

    }

    else if (state == Explosion) {
        explosionLoop();
    }
}