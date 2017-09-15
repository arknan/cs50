#include<stdio.h>
#include<cs50.h>

void printerd(int d, int l);
void printera(int a);

int main(void)
{
    printf("Please input the height of the half pyramid : \t");
    int l=get_int();
    while(true)
    {
        if(l>23 || l<0)
        {
            printf("Retry: \t");
            l=get_int();
        }
        else
            break;
    }
    
    for(int i=1;i<=l;i++)
    {
        printerd(i,l);
        printera(i);
        printf("  ");
        printera(i);
        printf("\n");
        
    }
}

void printerd(int d, int l)
{
    for(int j=l-d;j>0;j--)
    {
        printf(" ");
    }
}

void printera(int a)
{
    for(int j=0;j<a;j++)
    {
        printf("#");
    }
}