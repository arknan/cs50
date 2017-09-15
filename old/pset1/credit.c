#include<cs50.h>
#include<stdio.h>
#include<math.h>

int sum_of_digits(long long number, long long odd_or_even);
int even_addition(int digit);
int get_digits(long long number, long long loop, int decision);

int main(void)
{
    printf("Please enter a credit card number \n");
    long long number = get_long_long();
    int sum_even = sum_of_digits(number, 10);
    int sum_odd = sum_of_digits(number,1);
    int total = sum_even + sum_odd ;
    if((total % 10) == 0)
    {
        if((int)(number/1000000000000000) == 5)
        {
            printf("MASTERCARD\n");
        }
        else if( ( (int)(number/1000000000000000) == 4) || ( (int)(number/1000000000000) == 4) ) 
        {
            printf("VISA\n");
        }
        else if((int)(number/100000000000000) == 3)
        {
            printf("AMEX\n");
        }
    }
    else
        printf("INVALID\n") ; 
}

int sum_of_digits(long long number , long long odd_or_even)
{
     int calc = 0;
     int temp = 0;
     int decision = odd_or_even;
    
    for(int i=1;i<9;i++)
    {
        //printf("value of x is %lld \n" , odd_or_even);
        temp = ((get_digits(number, odd_or_even, decision)));
        if(decision==10)
        {
            temp = even_addition(temp);
        }
        else if(decision==1)
            {
               temp = temp + 0; 
            }
        else
        {
            printf("I am a stupid programmer, I messed up, sorry");
        }
        calc = calc + temp;
        odd_or_even = odd_or_even*100;
    }
    return calc;
}

int get_digits(long long number, long long loop, int decision)
{
    if((number/loop) > 0)
    {
        int digit = ((long long)(number / loop) % 10) ;
       // printf("The value of digit = %i\n", digit);
        if(decision==10)
        {
            digit = digit *2;
        }
        else if(decision==1)
        {
            digit = digit + 0;
        }
        else
        {
            printf("I am a stupid programmer, I messed up, sorry");
            digit = 0;
        }
        return digit;
    }
    else
        return 0;
}

int even_addition(int digit)
{
     if(digit > 9)
        {
            digit = ((digit % 10) + (int)(digit/10));
            return digit;
        }
        else
            return digit ;
}