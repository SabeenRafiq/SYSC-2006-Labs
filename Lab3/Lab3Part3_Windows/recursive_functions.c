/* SYSC 2006 Lab 3, part 3. */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "recursive_functions.h"



/* Exercise 1. Return the number of digits in integer n, n >= 0. */
int num_digits(int n)
{
    if (n==0){
        return 0;
    }
    return (num_digits(n/10) + 1);
}

/* Extra-practice exercises. */
/* Exercise 2. Return x raised to the power n for n >= 0. */
double power2(double x, int n){
    return -1;
}

