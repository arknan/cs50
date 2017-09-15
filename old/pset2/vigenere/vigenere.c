#include<stdio.h>
#include<stdlib.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>

int main(int argc, string argv[])
{
    // check if user gives exactly two arguments -> program name + key
    if(argc != 2)
    {
        printf("Usage:\t./vigenere k\nwhere \"k\" is the key for vigenere cipher\n");
        printf("Note: \"K\" can only be alphabetical, no numbers or whitespaces\n");
        return 1 ;
    }
        // check if the key is alphabetical, dont accept numbers/symbols/spaces
    int keylen = strlen(argv[1]);
   
    for(int x=0 ; x < keylen ; x ++)
    {
        if (!isalpha(argv[1][x]))
        {
            printf("Usage:\t./vigenere k\nwhere \"k\" is the key for vigenere cipher\n");
            printf("Note: \"K\" can only be alphabetical, no numbers or whitespaces\n");
            return 1 ; 
        }
    }
    
   
    printf("plaintext:");
    string s = get_string();
    int ptext_length = strlen(s);  
    int temp = 0;
    char new_key[ptext_length];
    
     for(int i=0, k=0 ; i <ptext_length ; i++, k++)
    {
        if(isalpha(s[i]))
        {
            new_key[i] = argv[1][k % keylen];
        }
        else
        {
            new_key[i] = s[i];
            k --;
        }
       // printf("\nvalue of array is %c %c", argv[1][k], new_key[i]);
    }
    
   // printf("\nvalue of array is %s \t %s", argv[1], new_key);
  
    for(int j=0; j<ptext_length;j++)
    {
        if(isblank(s[j]))
        {
            s[j] = s[j];
        }
        
        else if(islower(s[j])) 
            {
                if(islower(new_key[j]))
                {
                    temp =  ( ( (s[j] % 97) + (new_key[j] % 97) ) % 26) ;
                    s[j] = temp + 97;
                }
                else
                {
                    temp =  ( ( (s[j] % 97) + (new_key[j] % 65) ) % 26) ;
                    s[j] = temp + 97;
                }
          
            
            }
        else if(isupper(s[j]))
             {
                 if(isupper(new_key[j]))
                 {
                     temp =  ( ( (s[j] % 65) + (new_key[j] % 65) ) % 26);
                     s[j] = temp + 65;
                 }
                 else
                 {
                     temp =  ( ( (s[j] % 65) + (new_key[j] % 97) ) % 26);
                     s[j] = temp + 65;
                 }
             }
        else 
        {
            s[j] = s[j];
        }
    } 
    
    printf("ciphertext:%s\n", s);
    return 0; 
       
}