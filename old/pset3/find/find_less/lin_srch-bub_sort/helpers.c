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
    if(value <=0)
    {
       return false; 
    }
    else 
    {
        for(int i=0 ; i<n ; i++)
        {
            if(values[i] == value)
            {
                return true;
            }
        }
        return false;
    }
    
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    int temp =0;
    int swap = 1;
    for(int j=0;j<n;j++)
    {
        for(int k=j+1; k<n; k++)
        {
            if(swap != 0)
            {
                if(values[j] > values[k])
                {
                    temp = values[(k)];
                    values[(k)] = values[j];
                    values[j]=temp;
                    swap ++;
                }    
            }
        }
           
    }
    return;
}
