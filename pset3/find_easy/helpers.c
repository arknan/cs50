/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>

#include "helpers.h"
int middle(int base, int end);

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    if ( n <= 0 ) 
    {
        return false;
    }

    int base = 0 ;
    int end = n - 1 ; 
    int mid  = middle(base, end);
    do
    {
        if ( value == values[base] || value == values[end])
        {
            return true;
        } else if ( value > values[mid] ) 
        {
           base = mid ;
           mid = middle(base, end);
        } else if (value < values[mid] ) 
        {
            end = mid ;
            mid = middle(base,end);
        } else {
            return true;
        }
    } while ( (mid > base) && (mid < end) );
    return false ; 
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    int temp, swap ;
    for ( int i =0 ; i < n ; i ++ )
    {
        swap = 0 ;
        for ( int j = i + 1 ; j < n ; j ++ )
        {
            if ( values [i] > values [j] )
            {
                temp = values[i] ;
                values[i] = values[j] ;
                values[j] = temp ;
                swap = 1 ;
            }
        }
        if ( swap == 0 )
        {
            break ;
        }
    }

    return;
}

int middle(int base, int end)
{
    int mid ;
    if ((base + end)  % 2 == 0) 
    {
        mid = ( base + end ) / 2 ; 
    } else {
        mid = (base + end + 1) / 2 ; 
    }
    return mid ;
}
