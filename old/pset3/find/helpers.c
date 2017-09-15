/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include "helpers.h"


/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
     int start = 0 ; 
    int end =n-1 ;
    int middle = (floor)((end - start)/2);
  //  printf("value of s%i m%i e%i\n", start, middle, end);
    for(int i=0; i<n;i++)
    {
        if(start > end)
        {
         //   printf("value of s%i m%i e%i\n", start, middle, end);
            return false;
        }
        else
        {
            if( (value == values[middle]) || (value == values[start]) || (value ==values[end]) )
            {
              //  printf("STEP1:value of s%i m%i e%i %i %i %i\n", start, middle, end, values[start], values[middle], values[end]);
                return true;
            }
            
            else if(value > values[middle])
            {
                start = middle + 1;
                middle = (floor)((end+start)/2);
               // printf("STEP2:value of s%i m%i e%i %i %i %i\n", start, middle, end, values[start], values[middle], values[end]);
            }
            else if(value < values[middle])
            {
                end = middle -1;
                middle =(floor)((end+start)/2);
             //   printf("STEP3:value of s%i m%i e%i %i %i %i\n", start, middle, end, values[start], values[middle], values[end]);
            }
            
        }
        
    }
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n) sorting algorithm
    
   // print(values, n);
    int a[65536] = {0}; 
   // print(a, 65536);
    for(int i=0; i<n; i++)
    {
        a[values[i]] += 1;
    }
   // print(a, 65536);
   int temp = 0;
    
    for(int j=0; j<65536;j++)
    {
        if(a[j] > 0)
        {
            while(a[j] !=0)
            {
               // printf("a of temp currently has %i and temp is %i \n", a[j], temp);
                values[temp] = j;
                temp ++ ;
                a[j] -= 1; 
              //  printf("a of temp currently has %i and temp is %i \n", a[j], temp);
            }
        }
         
    }
  //  printf("askdfhklajsdfkjahf");
  //  print(values, n);
    return;
}


 void print(int values[], int n)
 {
     for(int i=0; i<n ; i++)
     {
         printf("%i\n", values[i]);
     }
 }