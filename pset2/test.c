#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<unistd.h>
char *crypt(const char *key, const char *salt);

int main(int argc, string argv[])
{
    if (argc !=2) 
    {
        printf("Usage: ./test password-to-encrypt\n");
        return 1;
    }
    string in = argv[1];
    string s = crypt(in, "50");
    printf("%s\n", s);
}
