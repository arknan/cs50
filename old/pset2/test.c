#include<stdio.h>
#include<string.h>
#include<cs50.h>


int main(void)
{
    string s = get_string();
    printf("The string length is : %lu", strlen(s));
    
}