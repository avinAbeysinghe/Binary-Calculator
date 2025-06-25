#include <operator.h>
/*
    Note: These operations are built for the idea that the numbers aren't negative. 
    TODO: make it work with pemdas
*/

int numset[2];
//int number[7];

int number = 0;
int exprIndex = 0;
int numsetIndex = 0; 
char operatorVal;

bool containsOperator(char& x){ //checks the closest operator (it's seperated to follow the order of operations)
    if(x == '*' || x =='/'){
        operatorVal = x;
        return true;
    }
    if(x == '+' || x == '-'){
        operatorVal = x;
        return true;
    }
    return false;
}

int preNullIndex(){ //finds the index of the first known null char
    for(int i = 0; i < (int)sizeof(problem); i++){
        if(problem[i] == '\0'){return i;}
    }
    return -1;
}
int operatorIndex(){ //check the index of any operator
    for(int i = 0; i < (int)sizeof(problem); i++){
        if(containsOperator(problem[i])){return i;}
    }
    return -1;
}

/*
* Create an entire number 
*/

// void createNumber(){
//     for(int digit : number){
//         numset[numsetIndex] = numset[numsetIndex] * 10 + digit;
//     }
//     ++numsetIndex;
// }

/*main expression*/
void checkExpression(){ //calculates the given expression
    if(containsOperator(problem[0])){ //make sure there is no operator at the beginning
        lcd.setCursor(0,0);
        lcd.print("INVALID EXPR");
    }
    // for(int i = exprIndex; i < preNullIndex(); ++i){
    //     for(int j = i; j < operatorIndex(); ++j){
    //         number[j] = problem[j] - '0'; 
    //     }
    //     //createNumber(); //creates a new number
    //     exprIndex = operatorIndex() + 1;
    // }   
    for(int i = 0; i < preNullIndex(); ++i) { //will keep going until it reaches a nullchar
    if (problem[i] == '*' || problem[i] == '/') { //shifts until it finds a m || d operator
        int left = 0, right = 0, l = i-1, r = i+1; 

        /*identifies the values that are left or right from the operator */
        // Find left operand
        while (l >= 0 && problem[l] >= '0' && problem[l] <= '9') l--;
        for (int j = l+1; j < i; ++j) left = left * 10 + (problem[j] - '0');
        // Find right operand
        while (r < preNullIndex() && problem[r] >= '0' && problem[r] <= '9') r++;
        for (int j = i+1; j < r; ++j) right = right * 10 + (problem[j] - '0');
        
        // Calculate result
        int nums = (problem[i] == '*') ? (left * right) : (left / right);
        
        i = l;
    }
    }
}



