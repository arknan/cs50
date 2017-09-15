#include <stdio.h>
#include <cs50.h>
int main(void)
{
    printf("What might be thy name, kind sir ..... OR madam ... I am not sexist.. go on .. give me answer : \t"); 
    string name = get_string();
    printf("Hello, %s\n", name);
} 