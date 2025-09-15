#ifndef C4_PROP_TICK_H
#define C4_PROP_TICK_H

#include <globals.h>

void drawTick() {
    lcd.setCursor(0, 0);
    lcd.print(seconds); //TODO: turn this into 00:00:00
    lcd.setCursor(0, 1);
    lcd.print(passwordOnDefusal);
}

void checkPassword() {
    if (passwordOnDefusal == password) {
        state = Defused;
    }
    else {
        passwordOnDefusal = "";
    }
}

void bombTick() {
    char key = keypad.getKey();
    if (key != NO_KEY) {
        if (key == '#') {
            checkPassword();
        }
        else if (key == '*') {
            passwordOnDefusal.remove(passwordOnDefusal.length()-1);
        }
        else {
            passwordOnDefusal += key;
        }
    }
    drawTick();
}

#endif