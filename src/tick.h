#ifndef C4_PROP_TICK_H
#define C4_PROP_TICK_H

#include <globals.h>

// Buzzer timing state
unsigned long lastBeep = 0;

// Determine beep interval based on remaining time
unsigned int getBeepIntervalMs(long remainingSeconds) {
    if (remainingSeconds <= 0) return 0;
    if (remainingSeconds <= 2) return 60; // very rapid at last 3 seconds
    if (remainingSeconds <= 5) return 110; // rapid at last 6 seconds
    if (remainingSeconds <= 10) return 200;     // fast under 10s
    if (remainingSeconds <= 15) return 400;
    if (remainingSeconds <= 60) return 800;     // moderate under 1 min
    if (remainingSeconds <= 120) return 1300;
    return 2000;                                 // once per second otherwise
}

// Update buzzer with non-blocking short blips using tone()
void updateBuzzer() {
    if (state != Ticking) return; // only during ticking
    const unsigned int interval = getBeepIntervalMs(seconds);
    if (interval == 0) return;
    const unsigned long now = millis();
    if (now - lastBeep >= interval) {
        lastBeep = now;
        // short beep; passive buzzer frequency 2kHz, duration 30ms (auto-stops)
        tone(BUZZER_PIN, 2000, 30);
    }
}

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
        noTone(BUZZER_PIN);
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
        noTone(BUZZER_PIN);
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

    // Update buzzer cadence
    updateBuzzer();
}

#endif