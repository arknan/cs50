#include <stdio.h>
#include <cs50.h>

int main(void)
{
    printf("Input the  half-pyramid’s height, a non-negative integer no greater than 23 \n");
    int height = get_int();
    int loop = 1;
    while (loop == 1)
    {
        if ( height < 0 || height > 23 )
        {
            printf("Retry \n");
            height = get_int();
        }
        else 
        {
            loop = 0 ;
        }
    }
    for (int i=0 ; i <height ; i++)
    {
        for (int j=0 ; j < height-1-i ; j++)
        {
            printf(" ");
        }
        for (int k=0 ; k < 1 + i ; k++)
        {
            printf("#");
        }
        printf("  ");
        for (int l=i+1; l > 0 ; l--)
        {
             printf ("#");
        }
        printf("\n");
    }
}
