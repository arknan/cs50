#include<stdio.h>
#include<stdlib.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>
#define _XOPEN_SOURCE
#include <unistd.h>

int main(int argc, string argv[])
{
    // check if user gives exactly two arguments -> program name + key
    if(argc != 2)
    {
        printf("Usage:\t./vigenere k\nwhere \"k\" is the key for vigenere cipher\n");
        printf("Note: \"K\" can only be alphabetical, no numbers or whitespaces\n");
        return 1 ;
    }