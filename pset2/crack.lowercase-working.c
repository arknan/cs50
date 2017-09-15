#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include <unistd.h>
char *crypt(const char *key, const char *salt);

void crack(string hash, string pass);
void loopy(string hash, string pass, int round);

int main ( int argc, string argv[])
{
    if ( argc != 2 )
    {
        printf ("Usage: ./crack hash\n");
        return 1;
    }

    string hash = argv[1];
    char pass[5] = {'a', '\0'};

    for ( int i = 0 ; i < 4 ; i ++ )
    {
        pass[i+1] ='\0' ;
        loopy(hash, pass, i);
    }
}

void crack(string hash, string pass)
{
    int res = 0 ;
    string result = crypt(pass, "50");
    int len = strlen(result);
    for ( int i = 0 ; i < len ; i++)
    {
        if ( result[i] == hash[i] )
        {
            res = 1 ;
        } else {
            res = 0 ;
            break ;
        }
    }
    if ( res == 1 )
    {
        printf("%s\n", pass);
        exit(0);
    }
}

void loopy(string hash, string pass, int round)
{
    if ( round == 0) 
    {
        for(char a = 'a' ; a < 'z' ; a ++)
        {
            pass[round] = a ;
            crack(hash, pass);
        }
    } else {
        for( char c='a' ; c < 'z' ; c ++ )
        {
            pass[round] = c ;
            loopy(hash, pass, (round -1) );
        }
    }
}
