#include<stdio.h>
#include<string.h>
#include<cs50.h>
#include<ctype.h>

int main(void)
{
    //printf("Please enter your full name \n");
    string s = get_string();
    int length = strlen(s);
    printf("%c", toupper(s[0]));
    
    for(int i=0 ; i<length ; i++)
    {
        if(s[i] == ' ') 
        {
            printf("%c",toupper(s[i+1]));
        }
        
    }
    printf("\n");
}