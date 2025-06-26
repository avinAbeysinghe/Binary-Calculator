
#include <globals.h>
/*
  TODO:
        Figure out how to do basic addition and subtraction
        Figure out how to display numbers on the binary system
*/

//==========================SET-UP && Initializing board values==========================//
const int digit[8] = {22, 23, 24, 25, 26, 27, 28, 29};
const int rs = 3, en = 4, d4 = 10 , d5 = 11, d6 = 12, d7 = 13;
const int contrastPin = 2; //adjusts the contrast of the Liquid Crystal Display w/o a potentiometer 
unsigned int exprIndex = 0;
char problem[50];

char keys[4][4] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte pin_row[4] = {33, 35, 37, 39};
byte pin_col[4] = {41, 43, 45, 47};

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
Keypad keypad(makeKeymap(keys), pin_row, pin_col, 4, 4);



void setup() {
  analogWrite(contrastPin, 250);
  //Serial.begin(9600);
  for(int i : digit)
    pinMode(i, OUTPUT);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0); lcd.print("Binary Calculator");
  lcd.setCursor(0, 1); lcd.print("Avin Abeysinghe");
  
  for(int i : digit){
    digitalWrite(i, HIGH);
    delay(500);
    digitalWrite(i, LOW);
  }

  lcd.clear();
  Serial.begin(9600);
}

//==========================Loop Code==========================//

void loop() {

  char getKey = keypad.getKey();
  for(int i = 0; i <= 9; i++){
    
    if(getKey == ('0' + i)){
      lcd.setCursor(exprIndex, 0);
      lcd.print(i);
      problem[exprIndex] = ('0' + i);
      delay(250);
      exprIndex++;
    }
  }

  /*Calculating & Entering Numbers*/
  switch(getKey){
    case '#': // Default Enter
      displaySolution(keypad);
      resetProblemArray();
      break;
    case 'A': // Addition
      insertOp('+');
      break;
    case 'B': // Subtract
      insertOp('-');
      break;
    case 'C': // Multiply
      insertOp('*');
      break;
    case 'D': // Divide
      insertOp('/');
      break;
    case '*':
      removeChar();
      break;
  }
  lcd.setCursor(0, 1);
  lcd.print("v.0.5");
}

