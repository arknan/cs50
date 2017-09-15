#include<stdio.h>
#include<cs50.h>
#include<math.h>

int main(void)
{
    printf("Hello, how much change is owed ? : \t");
    float change = get_float();
    while(true)
    {
        if (change < 0)
        {
            printf("Retry : \t");
            change = get_float();
        }
        else
            break;
    }

    int count = 0;
    change = change * 100;

    while(true)
    {
        if (change >= 25)
        {
            change = change - 25 ;
            count ++ ;
        }
        
        else if (change >=10)
        {
            change = round(change -  10);
            count ++ ;
        }
        
        else if (change >=5)
        {
            change = round(change  - 5) ;
            count ++ ;
        }
        
        else if (change >=1)
        {
            change = round(change - 1)  ;
            count ++ ;
        }
        else
            break;
        
    }
    printf("%i\n", count) ;
} 



   /* while(true)
    {
        switch(change)
        {
            case(change>=25):
            {
                change = round(change - 25) ;
                count ++ ;
            }
            
            case(change>=10):
            {
                change = round(change - 10) ;
                count ++ ;
            }
            
            case(change>=5):
            {
                change = round(change - 5) ;
                count ++ ;
            }
            
            case(change>=1):
            {
                change = round(change - 1) ;
                count ++ ;
            }
        }
    } */
    
   // printf("change is %f", change);