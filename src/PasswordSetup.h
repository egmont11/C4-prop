#ifndef UNTITLED_PASSWORDSETUP_H
#define UNTITLED_PASSWORDSETUP_H

#include <globals.h>

void drawPassword() {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("PSWD:");
    lcd.setCursor(0, 1);
    lcd.print(password);
}

void setupPassword() {
    char key = keypad.getKey();

    if (key == NO_KEY) {
        return;
    }
    if (key == '*') {
        // Backspace functionality
        if (password.length() > 0) {
            password.remove(password.length() - 1);
        }
    }
    else {
        password += key;
    }

    drawPassword();
}

#endif //UNTITLED_PASSWORDSETUP_H