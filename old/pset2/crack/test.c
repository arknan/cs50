#include<stdio.h>
#include<stdlib.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>

int main(void)
{
    char x = '/';
    if(isalpha(x))
    {
        printf("value of \t %c\n", x);
    }
    else
        printf("False");
    
}