#ifndef GLOBALS_H
#define GLOBALS_H

#include <Arduino.h>
#include <LiquidCrystal.h>
#include <Keypad.h>

extern const int rs, en, d4, d5, d6, d7;
extern const int contrastPin;  
extern unsigned int cursorPos;
extern unsigned int problemIndex;

extern char keys[4][4];
extern char problem[50];
extern byte pin_row[4];
extern byte pin_col[4];
extern const int digit[8];

extern LiquidCrystal lcd;
extern Keypad keypad;

extern void insertOp(char x);
extern void resetProblemArray();
extern void displaySolution(Keypad& key);
extern void removeChar();

#endif //GLOBALS_H