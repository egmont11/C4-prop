#ifndef C4_PROP_TICK_H
#define C4_PROP_TICK_H

#include <globals.h>

void drawTick() {
    int hours = seconds / 3600;
    int minutes = (seconds % 3600) / 60;
    int secondsLocal = seconds % 60;

    char buffer[9]; // "HH:MM:SS" + null terminator
    sprintf(buffer, "%02d:%02d:%02d", hours, minutes, secondsLocal);

    lcd.setCursor(0, 0);
    lcd.print("TIME: ");
    lcd.print(buffer);
    lcd.setCursor(0, 1);
    lcd.print("PSWD: ");
    lcd.print(passwordOnDefusal);
}

void checkPassword() {
    if (passwordOnDefusal == password) {
        state = Defused;
        lcd.clear();
        lcd.print("CORRECT PASSWORD");
        lcd.setCursor(0, 1);
        lcd.print("TIME: ");
        int hours = seconds / 3600;
        int minutes = (seconds % 3600) / 60;
        int secondsLocal = seconds % 60;

        char buffer[9]; // "HH:MM:SS" + null terminator
        sprintf(buffer, "%02d:%02d:%02d", hours, minutes, secondsLocal);
        lcd.print(buffer);
    }
    else {
        passwordOnDefusal = "";
        lcd.clear();
        lcd.print("WRONG PASSWORD");
        delay(1000);
        lcd.clear();
    }
}

void DoTick() {
    if (seconds > 0) {
        seconds -= 1;
    }
    else {
        state = Explosion;
    }
}

unsigned long lastTick = 0;

void bombTick() {
    const char key = keypad.getKey();
    if (key != NO_KEY) {
        if (key == '#') {
            checkPassword();
        }
        else if (key == '*') {
            if (passwordOnDefusal.length() > 0) {
                passwordOnDefusal.remove(passwordOnDefusal.length() - 1);
            }
        }
        else {
            passwordOnDefusal += key;
        }
    }
    else {
        drawTick();
    }

    // Countdown every 1000 ms
    if (millis() - lastTick >= 1000) {
        lastTick = millis();
        DoTick();
    }
}

#endif