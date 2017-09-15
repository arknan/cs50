#include<stdio.h>
#include<stdlib.h>
#include<cs50.h>
#include<string.h>

void lower_convert (int pi, int ki, char casetype, string plain, string k);

int main (int argc, string argv[]) 
{
    if ( argc > 2 || argc == 1 )
    {
        printf ("Usage ./vigenere k\n");
        return 1;
    }
    
    string k = argv[1] ;
    int keylen = strlen(k);

    for ( int c = 0 ; c < keylen ; c ++ ) // get the pun ?? :D
    {
        if ( k[c] >= 'a' && k[c] <= 'z' ) 
        {
            k[c] -= 'a';
        }
        else if ( k[c] >= 'A' && k[c] <= 'Z' )
        {
            k[c] -= 'A' ;
        }
        else
        {
            printf ("Fatal error : We do not accept non-alphabetical characters in the key\n");
            return 1;
        }
    }

    printf ("plaintext:");
    string plain = get_string();
    printf("ciphertext:");
    int plen = strlen(plain);
    int kcount = 0;

    for ( int i =0 ; i < plen ; i++)
    {
        if ( ( plain[i] >= 'a' && plain[i] <= 'z' ) ) 
        {
            if ( kcount < keylen )
            {
                lower_convert(i,kcount, 'l', plain, k);
                kcount ++ ;
            } else {
                kcount = 0 ;
                lower_convert(i,kcount, 'l', plain, k);
                kcount ++;
            }
        } else if ( plain[i] >= 'A' && plain[i] <= 'Z') {
            if ( kcount < keylen )
            {
                lower_convert(i, kcount, 'u', plain, k);
                kcount ++ ;
            } else {
                kcount=0;
                lower_convert(i,kcount, 'u', plain, k);
                kcount ++ ;
            }
        } else {
            printf("%c", plain[i]);
        }
    }
    printf("\n");
    return 0;

}

void lower_convert (int pi, int ki, char casetype, string plain, string k)
{
    if ( casetype == 'l' )
    {
        if (  (plain[pi] + k[ki]) >= 'a' && (plain[pi]+k[ki]) <= 'z' )
        {
             printf("%c", (char) (plain[pi] + k[ki] ) ) ;
        } else {
            printf("%c", (char) (plain[pi] + k[ki] -26 ) ) ;
        }
    } else if (casetype == 'u') {
        if (  (plain[pi] + k[ki]) >= 'A' && (plain[pi]+k[ki]) <= 'Z' )
        {
            printf("%c", (char) (plain[pi] + k[ki] ) ) ;
        } else {
            printf("%c", (char) (plain[pi] + k[ki] -26 ) ) ;
        }
    } else {
        printf ("Fatal Error : You should have never landed in this place, its an internal bug, contact the developer\n");
        exit(3);
    }
}
