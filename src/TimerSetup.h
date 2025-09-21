#ifndef UNTITLED_TIMERSETUP_H
#define UNTITLED_TIMERSETUP_H

#include <globals.h>

int lastMinutes = -1; // remember last value

void drawTimer() {
    if (minutes != lastMinutes) {
        lcd.setCursor(0, 0);
        lcd.print("Minutes:");

        lcd.setCursor(0, 1);
        char buffer[5];
        sprintf(buffer, "%-4d", minutes); // print with padding
        lcd.print(buffer);

        lastMinutes = minutes;
    }
}

void setupTimer() {
    const char key = keypad.getKey();

    if (key != NO_KEY) {
        if (key == '*') {
            // Backspace functionality
            if (minutes > 0) {
                minutes -= 1;
            }
        }
        else if (key == '#') {
            state = Ticking;
            seconds = minutes*60;
            lcd.clear();
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
                    break;
                case '8':
                    minutes += 8;
                    break;
                case '9':
                    minutes += 9;
                    break;
            }
        }
    }

    drawTimer();
}

#endif //UNTITLED_TIMERSETUP_H