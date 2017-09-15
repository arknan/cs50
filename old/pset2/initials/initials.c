#include<stdio.h>
#include<string.h>
#include<cs50.h>
#include<ctype.h>

int main(void)
{
    //printf("Please enter your full name \n");
    string s = get_string();
    int length = strlen(s);
    
    if((s[0] >= 'a' && s[0] <= 'z') || (s[0] >= 'A' && s[0] <= 'Z'))
    {
        printf("%c",toupper(s[0]));
    }
    
    for(int i=0 ; i<length ; i++)
    {
        if(s[i] == ' ' && ( (s[i+1] >= 'a' && s[i+1] <= 'z' ) || (s[i+1] >= 'A' && s[i+1] <= 'Z' )))
        {
            printf("%c",toupper(s[i+1]));
        }
    }
    printf("\n");
}