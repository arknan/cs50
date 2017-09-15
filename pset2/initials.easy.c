#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>

int main (void)
{
    printf ("Please enter your name : \n");
    string s = get_string();
    int len = strlen(s);
    int tmp = 0;


    for (int i=0 ; i < len ; i++)
    {
        if ( i == 0 )
        {
            printf ("%c", toupper(s[i]));
        }

        if (tmp == 1)
        {
            printf ("%c", toupper(s[i]));
            tmp = 0 ;
        }

        if ( s[i] == ' ' )
        {
            tmp = 1;
        }

    }
    printf ("\n");
}
