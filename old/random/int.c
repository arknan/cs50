#include <stdio.h>
#include <cs50.h>
int main(void)
{
    printf("please enter a number: \t");
    int i = get_int();
    printf("Hello, %i\n", i);
}