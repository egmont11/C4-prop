#include <globals.h>
#include <PasswordSetup.h>
#include <TimerSetup.h>
#include <tick.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const byte ROWS = 4;  //four rows
const byte COLS = 3;  //four columns
char keys[ROWS][COLS] = {
    { '1', '2', '3'},
    { '4', '5', '6'},
    { '7', '8', '9'},
    { '*', '0', '#'}
};
byte rowPins[ROWS] = { 13, 10, 9};  //connect to the row pinouts of the keypad
byte colPins[COLS] = { 7, 6, A1 };  //connect to the column pinouts of the keypad
//Create an object of keypad
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

State state;
String password;
int minutes;

void setup() {
    state = SetPassword;
    password = "";
    minutes = 0;
}

void loop() {
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
}