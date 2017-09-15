#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>

void check_space(string s, int i);

int main (void)
{
    printf("Please enter your name \n");
    string s = get_string();
    int len = strlen(s);

    for ( int i = 0 ; i < len ; i++ )
    {
        check_space(s,i);
    }
    printf("\n");
}

void check_space(string s, int i)
{
    if (i == 0) 
    {
        if ( (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') )
        {
            printf ("%c", toupper(s[i]));
        }
    }

    if ( s[i] == ' ')
    {
        if ( (s[i+1] >= 'a' && s[i+1] <= 'z') || (s[i+1] >= 'A' && s[i+1] <= 'Z') ) 
        {
            printf ("%c", toupper(s[i+1]));
        }
    }

}

