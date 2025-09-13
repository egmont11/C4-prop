#include <globals.h>
#include <PasswordSetup.h>
#include <TimerSetup.h>
#include <tick.h>

LiquidCrystal lcd(7,6, 5, 4, 3, 2);
const byte ROWS = 4;  //four rows
const byte COLS = 3;  //four columns
char keys[ROWS][COLS] = {
    { '1', '2', '3'},
    { '4', '5', '6'},
    { '7', '8', '9'},
    { '*', '0', '#'}
};
byte rowPins[ROWS] = { A0, A1, A2, A3};  //connect to the row pinouts of the keypad
byte colPins[COLS] = { A4, A5, 13 };  //connect to the column pinouts of the keypad
//Create an object of keypad
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

State state;
String password;
int minutes;

void setup() {
    lcd.begin(16, 2);
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