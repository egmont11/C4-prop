#ifndef C4_PROP_EXPLOSION_H
#define C4_PROP_EXPLOSION_H

#include <globals.h>

void explosionLoop() {
    lcd.print("KABOOOOM");
    lcd.setCursor(0, 1);
    lcd.print("            ");
}

#endif //C4_PROP_EXPLOSION_H