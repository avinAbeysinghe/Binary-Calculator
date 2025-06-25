#include <globals.h>
#include <operator.h>

void insertOp(char x){
  lcd.setCursor(cursorPos, 0);
  lcd.print(x);
  problem[problemIndex] = x;
  cursorPos++;
  problemIndex++;
}

void printProblem(){ //debugger
    for(char i : problem)
        Serial.print(i);
    Serial.println((int)sizeof(problem)); //checks if the array is always sized 50.
}

void resetProblemArray(){
    printProblem();
    for(char i : problem){
        if(i == '\0')
            break;
        i = '\0';
    }
    Serial.println("\nProblem has been resetted");
    printProblem();
    problemIndex = 0, cursorPos = 0;
    lcd.clear();
}

void removeChar(){
    if(cursorPos == 0){return;} //preventing it from going beyond board limit.

    cursorPos--;
    problemIndex--; 
    lcd.setCursor(cursorPos, 0);
    lcd.print(' ');
    problem[problemIndex] = '\0';
}

void displaySolution(Keypad& key){
    lcd.setCursor(0, 0);
    for(int i = 0; i < 16; i++)
        lcd.print(' ');
    lcd.setCursor(15, 1);
    lcd.rightToLeft();
    lcd.print("test");
    while(keypad.getKey() == NO_KEY){delay(50);}
    lcd.leftToRight();
}