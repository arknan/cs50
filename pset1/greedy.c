#include<stdio.h>
#include<cs50.h>
#include<math.h>

double quotient(double ichange, int val);

int main(void)
{
    int val_quarter = 25; 
    int val_dime = 10 ; 
    int val_nickel = 5 ;
    int val_penny = 1 ; 
    int no_of_coins = 0 ;
    float change; 

    do
    {
        printf("How much change is owed ?\n");
        change = get_float();
    } while ( change < 0 );
    double ichange = round(change * 100) ;

    while ( ichange != 0 )
    {
        if ( ichange - val_quarter >= 0 ) 
        {
            int q = quotient(ichange, val_quarter);
            ichange = (ichange - (val_quarter * q));
            no_of_coins += q;
        }
        else if ( ichange - val_dime >=0 )
        {
            int q = quotient(ichange, val_dime);
            ichange = (ichange - (val_dime * q));
            no_of_coins += q;
        }
        else if ( ichange - val_nickel >=0 )
        {
            int q = quotient(ichange, val_nickel);
            ichange = (ichange - (val_nickel * q));
            no_of_coins += q;
        }
        else if ( ichange - val_penny >=0 )
        {
            int q = quotient(ichange, val_penny);
            ichange = (ichange - (val_penny * q));
            no_of_coins += q;
        }
    }
    printf("%d\n", no_of_coins);
}

double quotient(double ichange, int val)
{
    return (ichange / val);
}
