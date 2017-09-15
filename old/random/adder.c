#include <cs50.h>
#include <stdio.h>

int main(void)
{
    printf("Welcome to the adder \n\n");
    printf("Please enter the value of the first number : \t");
    int x = get_int();
    printf("Please enter the value of the second number : \t");
    int y = get_int();
    /*int z = x + y ;*/
    printf("The sum is : \t %i \n", x+y);
}