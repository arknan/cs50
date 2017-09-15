#include<stdio.h>
#include<cs50.h>

void bottles(int length);

int main(void)
{
    printf("Please enter the number of your shower in minutes : \t");
    int length = get_int();
    bottles(length);
}

void bottles(int length)
{
    printf("Your shower time of %i minutes is equivalent to %i bottles of water \n", length, ( (int) ( (length*1.5*128)/16) ) );
}