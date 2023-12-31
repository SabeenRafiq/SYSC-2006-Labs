/* SYSC 2006 Lab 4.

 * Incomplete implementations of the functions that will be coded during the lab.
 */

#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#include "arrays.h"

/* Exercise 1. */

/* Return the average magnitude of the signal represented by
 * the n doubles in x[].
 * This function assumes that parameter n is >= 1.
 */
double avg_magnitude(double x[], int n)
{
    double sum = 0;
    for (int i = 0; i < n; i += 1)
    {
        if (x[i] < 0)
        {
            sum += ((-1) * x[i]);
        }
        else
        {
            sum += x[i];
        }
    }
    return sum / n;
}

/* Exercise 2. */

/* Return the average power of the signal represented by
 * the n doubles in x[].
 * This function assumes that parameter n is >= 1.
 */
double avg_power(double x[], int n)
{
    double sum_squared = 0;
    for (int i = 0; i < n; i += 1)
    {
        sum_squared += (x[i])*(x[i]);
    }
    return sum_squared / n;
}

/* Exercise 3. */

/* Return the largest of the n doubles in arr[].
 * This function assumes that parameter n is >= 1.
 */
double maxi(double arr[], int n)
{
    double max_val = arr[0];
    for (int i = 1; i < n; i += 1)
    {
        if (max_val < arr[i]) {
            max_val = arr[i];
        }
    }
    return max_val;
}

/* Exercise 4. */

/* Return the smallest of the n doubles in arr[].
 * This function assumes that parameter n is >= 1.
 */
double mini(double arr[], int n)
{
    double min_val = arr[0];
    for (int i = 1; i < n; i += 1)
    {
        if (min_val > arr[i]) {
            min_val = arr[i];
        }
    }
    return min_val;
}

/* Exercise 5. */

/* Normalize the n doubles in x[].
 * This function assumes that parameter n is >= 2, and that at least
 * two of the values in x[] are different.
 */
void normalize(double x[], int n)
{
    double minx = mini(x,n);
    double maxx = maxi(x,n);
    for (int i = 0; i < n; i++){
        x[i] = (x[i]-minx) / (maxx - minx);
    }
   
}
