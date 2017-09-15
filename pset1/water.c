#include <stdio.h>
#include <cs50.h>

int main(void)
{
    printf("Please enter the length of your shower in minutes\n");
    int len_shower = get_int();
    int shower_to_bottle = 12 ;
    printf("Equivalent number of bottles of water is : %d \n", len_shower * shower_to_bottle);
}

