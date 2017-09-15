#include<stdio.h>
#include<string.h>
#include<cs50.h>

int main(void)
{
    string s = get_string();
    char c = (s[0] + 1) % 26 ;
    printf("first letter is %s %c", s, c);
}