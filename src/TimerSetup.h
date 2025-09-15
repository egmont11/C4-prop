#ifndef UNTITLED_TIMERSETUP_H
#define UNTITLED_TIMERSETUP_H

#include <globals.h>

void drawTimer() {
    lcd.setCursor(0, 0);
    lcd.print("Minutes:");
    lcd.setCursor(0, 1);
    lcd.print(minutes);
}

void setupTimer() {
    char key = keypad.getKey();

    if (key != NO_KEY) {
        if (key == '*') {
            // Backspace functionality
            if (minutes > 0) {
                minutes - 1;
            }
        }
        else if (key == '#') {
            state = Ticking;
        }
        else {
            switch (key) {
                case '1':
                    minutes += 1;
                    break;
                case '2':
                    minutes += 2;
                    break;
                case '3':
                    minutes += 3;
                    break;
                case '4':
                    minutes += 4;
                    break;
                case '5':
                    minutes += 5;
                    break;
                case '6':
                    minutes += 6;
                    break;
                case '7':
                    minutes += 7;
                case '8':
                    minutes += 8;
                    break;
                case '9':
                    minutes += 9;
                    break;
            }
            password += key;
        }
    }
}

#endif //UNTITLED_TIMERSETUP_H