# C4 prop

An Arduino-based "C4" bomb prop with keypad input and 16x2 LCD display. The device lets you:
- Set a disarm password using a 3x4 matrix keypad
- Configure a countdown timer (minutes/seconds)
- Start a ticking countdown on the LCD
- Handle defusal and explosion end states (logic WIP)

This repository uses PlatformIO to build and upload firmware for an Arduino Uno.


## Tech stack
- Language: C/C++ (Arduino)
- Board/MCU: Arduino Uno (ATmega328P)
- Framework: Arduino (via PlatformIO)
- Package manager/build system: PlatformIO (platformio.ini configured)
- External libraries (from `platformio.ini`):
  - Keypad (chris--a/Keypad@^3.1.1)
  - LiquidCrystal (arduino-libraries/LiquidCrystal@^1.0.7)

Entry points:
- `src/main.cpp` (Arduino `setup()` and `loop()`)
- Supporting headers in `src/` provide state handling and helpers.


## Requirements
- PlatformIO Core (CLI) or PlatformIO in VS Code / CLion
  - Install CLI: `pip install platformio` or see https://platformio.org/install
- A supported toolchain will be installed automatically by PlatformIO
- Hardware:
  - Arduino Uno
  - 16x2 LCD (HD44780-compatible) wired to pins: `rs=7, enable=6, d4=5, d5=4, d6=3, d7=2`
  - 3x4 matrix keypad
  - Keypad pins (from code):
    - Rows (A3, A2, A1, A0)
    - Cols (12, A5, A4)
  - Passive buzzer on digital pin D8 (with a series resistor if needed)


## Setup
1. Clone the repository
2. Install PlatformIO
3. Connect the Arduino Uno via USB
4. Ensure the correct serial port is selected (PlatformIO usually auto-detects)

Project configuration is in `platformio.ini` under the environment `[env:uno]`.


## Build, Upload, and Monitor
From the project root:

- Build firmware:
  - `pio run`
- Upload to board:
  - `pio run -t upload`
- Open serial monitor (adjust baud if you add Serial):
  - `pio device monitor`

Alternatively, use the PlatformIO IDE buttons for Build, Upload, and Monitor.


## Scripts
There are no custom scripts defined. Standard PlatformIO targets are available:
- `pio run` (build)
- `pio run -t upload` (upload)
- `pio run -t clean` (clean)
- `pio device monitor` (serial monitor)


## Environment variables
No environment variables are required at this time.
- TODO: Document any future configuration that may move to environment variables.


## Tests
This project is set up for PlatformIO Unit Testing, but no tests are currently implemented.
- To run tests (once added under `test/`): `pio test`
- See `test/README` and PlatformIO docs: https://docs.platformio.org/en/latest/advanced/unit-testing/index.html


## Project structure
- `platformio.ini` — PlatformIO config (env: `uno`, Arduino framework, lib deps)
- `src/`
  - `main.cpp` — main entry with keypad/LCD setup and state machine skeleton
  - `globals.h` — shared globals and `enum State` declarations
  - `PasswordSetup.h` — password setup logic (helper, used by `main.cpp`)
  - `TimerSetup.h` — timer setup logic (helper)
  - `tick.h` — ticking/countdown logic (helper)
  - `Explosion.h` — explosion/end-state helper
- `include/` — headers for the project (none beyond README placeholder)
- `lib/` — private libraries (none beyond README placeholder)
- `test/` — unit tests (none yet; README placeholder)
- `LICENSE.md` — project license
- `README.md` — this file


## Usage notes
- LCD is initialized as `LiquidCrystal lcd(7,6,5,4,3,2)`
- Keypad layout (3x4):
  1 2 3
  4 5 6
  7 8 9
  * 0 #
- Keypad pin mapping per code comments appears reversed; verify column/row wiring in hardware.
- States defined: `SetPassword`, `SetTimer`, `Ticking`, `Defused`, `Explosion`.
- Passive buzzer feedback: beeps once per second when >1 minute remains, speeds up under 1 minute, very rapid in the last 3 seconds.

TODOs:
- Complete the logic for `Defused` and `Explosion` handling
- Add serial output for debugging and define a monitor baud rate
- Add unit tests under `test/`
- Document exact keypad wiring and any required resistors/buzzer/LEDs if used


## License
This project is licensed under the terms described in `LICENSE.md`.
