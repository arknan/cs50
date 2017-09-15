#include<stdio.h>
#include<stdlib.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>

int main(int argc, string argv[2])
{
    if(argc != 2)
    {
        printf("Invalid input \n");
        return 1 ;
    }
    
    int i = atoi(argv[1]);
    i = i % 26;
    printf("plaintext:");
    string s = get_string();
    int length = strlen(s);
    int temp;
    
    for(int j=0; j<length;j++)
    {
        if((s[j] >= 'a') && (s[j] <= 'z'))
        {
            temp =  ( (s[j] % 97 + i ) % 26) ;
            s[j] = temp + 97;
            
        }
        else if((s[j] >= 'A') && (s[j] <= 'Z'))
        {
            temp =  ( (s[j] % 65 + i ) % 26);
            s[j] = temp + 65;
        }
        else
        {
            s[j] = s[j];
        }
    }
    
    printf("ciphertext:%s", s);
    return 0;
        
}