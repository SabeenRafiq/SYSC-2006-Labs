/* fraction.c - SYSC 2006 Lab 6 */

#include <stdlib.h> // abs(x)
#include <stdio.h>  // printf

#include "struct_string.h"

/* Print fraction f in the form a/b. */
void print_fraction(const fraction_t* pf)
{
    printf("%d/%d", pf->num, pf->den);
}

/* Return the greatest common divisor of integers a and b;
   i.e., return the largest positive integer that evenly divides
   both values.
*/
int gcd(int a, int b)
{
    /* Euclid's algorithm, using iteration and calculation of remainders. */
    int q = abs(a);
    int p = abs(b);
    int r = q % p;
    while (r != 0)
    {
        q = p;
        p = r;
        r = q % p;
    }
    return p;
}

/* Return the reduced form of fraction f.

   This means that:
   (1) if the numerator is equal to 0 the denominator is always 1.
   (2) if the numerator is not equal to 0 the denominator is always
       positive, and the numerator and denominator have no common
       divisors other than 1.

   In other words,
   (1) if the numerator is 0 the denominator is always changed to 1.
   (2) if the numerator and denominator are both negative, both values
       are made positive, or if the numerator is positive and the
       denominator is negative, the numerator is made negative and the
       denominator is made positive.
   (3) the numerator and denominator are both divided by their greatest
       common divisor.
*/
void reduce(fraction_t *f)
{

    if (f->num == 0)
    {
        f->den = 1;
    }
    else if ((f->num < 0 && f->den < 0) || f->den < 0)
    {
        f->num = f->num * -1;
        f->den = f->den * -1;
    }

    int gcf = gcd(f->num, f->den);
    f->num = f->num / gcf;
    f->den = f->den / gcf;
}

/* Return a fraction with numerator a and denominator b.
   Print an error message and terminate the calling program via exit()
   if the denominator is 0.
   The fraction returned by this function is always in reduced form
   (see documentation for reduce).
*/
void make_fraction(int a, int b,fraction_t* pf)
{
    pf -> num = a;
    pf -> den = b; 
    reduce(pf);
}

/* Return the sum of fractions f1 and f2.
   The fraction returned by this function is always in reduced form
   (see documentation for reduce).
 */
void add_fractions(const fraction_t* pf1, const fraction_t* pf2, fraction_t* psum)
{
    int num = 0;
    int den = 0;

    num = pf1->num * pf2->den + pf1->den * pf2->num;
    den = pf1->den * pf2->den;

    make_fraction(num, den, psum);
}

/* Return the product of fractions f1 and f2.
   The fraction returned by this function is always in reduced form
   (see documentation for reduce).
 */
void multiply_fractions(const fraction_t* pf1, const fraction_t* pf2, fraction_t* pprod)
{
    int num = 0;
    int den = 0;

    num = pf1->num * pf2->num;
    den = pf1->den * pf2->den;

    make_fraction(num, den, pprod);
}
