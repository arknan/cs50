/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    if ( n <= 0 ) 
    {
        return false;
    }

    int mid ;
    int base = 0 ;
    int end = n; 


    while ( base < end )
    {
        if ( value > values[mid] ) 
        {
           base = mid ;

    return false ;

}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    int temp, swap ;
    for ( int i =0, range = n -1 ; i < range ; i ++ )
    {
        swap = 0 ;
        for ( int j = i + 1 ; j < range ; j ++ )
        {
            if ( values [i] > values [j] )
            {
                temp = values[i] ;
                values[i] = values[i+1] ;
                values[i+1] = tmep ;
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
    if ( end % 2 == 0) 
    {
        mid = ( end + base ) / 2 ; 
    } else {
        mid = (end-1) / 2 ; 
    }
}
