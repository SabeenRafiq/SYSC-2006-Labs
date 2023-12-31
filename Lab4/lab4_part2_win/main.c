#include<stdio.h>
#include<stdlib.h>
#include "lab4test.h"
#include "lab4test.c"

int variable1;
int main(void){
    variable1 = 0;
    int i = 100;
    for (int i = 0; i < 8; i++){
        printf("The value of variable1 is: %d\n", variable1);
        variable1++;
    }

    i = test1(variable1);

    return EXIT_SUCCESS;
}

/*
- What is the scope of variable1 defined inside main.c?
    Within main.c (global)
- Are any of the variables variable1 defined inside lab4test.c the same as the variable defined inside
main.c?
    No
- Does the assignment statement inside lab4test.c (line 7) modify the content of variable1 inside
main.c?
    No it is a different variable
- How many distinct variables i there are in main.c? If more than one, what is the scope of each of
them?
    There are two. The first one has the scope the main.c file
    The second has a scope within the for loop
- How many distinct variables variable1 there are in main.c? If more than one, what is the scope
of each of them?
    There is one varable1 in main.c. Its scope is the main.c file
- In lab4test.c, is the variable1 inside test2 the same as the variable inside test1?
    No
*/