#include<stdio.h>
#include<cs50.h>
#include<math.h>

int main(void)
{
    printf("Enter a credit card number \n");
    long long ccn = get_long_long();
    int even = 0;
    int odd = 0;
    int hundred = 0; 
    int temp=0;
    int count =0 ;
    long long temp_ccn = ccn ;
    long long temp_ccn_2 = ccn ;
    
    while (temp_ccn > 0 )
    {
        count += 1;
        temp_ccn /=10;
    }
    while (ccn > 0)
    {
        odd += ccn % 10;
        hundred = ccn % 100 ;
        temp = 2 * ( (int) ( floor ( hundred / 10 ) ) );
        if (temp > 9)
        {
           int lhs = temp % 10;
           int rhs = (int) ( floor ( temp / 10 ) );
           even += lhs + rhs ; 
        } else 
        {
            even += temp ;
        }
        ccn /= 100 ;
    }

    int verify = ( ( even + odd ) % 10 );
    if (verify == 0) 
    {
        if (count == 15)
        {
            printf ("AMEX\n");
        } else if (count == 13)
        {
            printf("VISA\n");
        } else if (count == 16)
        {
            if ( round ( temp_ccn_2 / ( (long long) pow(10,15) ) ) == 4 )
            {
                printf("VISA\n");
            } else if ( round ( temp_ccn_2 / ( (long long) pow(10,15) ) ) == 5)
            {
                printf("MASTERCARD\n");
            } else
            {
                printf("INVALID\n");
            }
        }
    }
    else
    {
        printf("INVALID\n");
    }

}

