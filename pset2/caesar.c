#include<stdio.h>
#include<stdlib.h>
#include<cs50.h>
#include<string.h>

int main (int argc, string argv[]) 
{
    if ( argc > 2 || argc == 1 )
    {
        printf ("The program needs exactly 1 non negative input\n");
        return 1;
    }
    int k = ( atoi(argv[1]) ) % 26  ;
    
    printf ("plaintext:");
    string plain = get_string();
    printf("ciphertext:");
    int len = strlen(plain);

    for ( int i =0 ; i < len ; i++)
    {
        if ( ( plain[i] >= 'a' && plain[i] <= 'z' ) || ( plain[i] >= 'A' && plain[i] <= 'Z') )
        {
            if ( ( (plain[i] + k) >= 'a' && (plain[i]+k) <= 'z' ) || ( (plain[i]+k) >= 'A' && (plain[i]+k) <= 'Z')  )
            {
                printf("%c", plain[i]+k ) ;
            }
            else 
            {
                printf("%c", plain[i] + k -26 ) ;
            }
        }
        else 
        {
            printf("%c", plain[i]);
        }
    }
    printf("\n");
    return 0;

}

