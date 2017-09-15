#include<stdio.h>
#include<cs50.h>
#include<math.h>



int main(void)
{
    int x[20];
    printf("Please enter your credit card number :\n");
    long long i =get_long_long();
    
    while(true)
    {
        if (i<=0)
        {
            printf("Retry:\t");
            i = get_long_long();
        }
        else
            break;
    }
    for(int j=0; j<16; j++)
    {
        x[j] = digit(i, j)
    }
}

int digit(long long x, int y)
{
     
}
    
  /*  //i = round(i / 10);
   // printf("The number you entered is \n %lld\n", i);

    int d1 = i % 10 ;
    printf("First digit is \t%i\n", d1);
    
    int d2 = round(i/10) ;
    d2 = d2 % 10 ;
    printf("Second digit is\t%i\n", d2);
    
    int d3 = round(i/100) ;
    d3 = d3 % 10 ;
    printf("Third digit is\t%i\n", d3);
    
     int d4 = round(i/1000) ;
    d4 = d4 % 10 ;
    printf("Fourth digit is\t%i\n", d4);
    
    
     int d5 = round(i/10000) ;
    d5 = d5 % 10 ;
    printf("Fifth digit is\t%i\n", d5);
    
    
     int d6 = round(i/100000) ;
    d6 = d6 % 10 ;
    printf("Sixth digit is\t%i\n", d6);
    
     int d7 = round(i/1000000) ;
    d7 = d7 % 10 ;
    printf("Seventh digit is\t%i\n", d7);
    
     int d8 = round(i/10000000) ;
    d8 = d8 % 10 ;
    printf("Eigth digit is\t%i\n", d8);
    
     int d9 = round(i/100000000) ;
    d9 = d9 % 10 ;
    printf("Nineth digit is\t%i\n", d9);
    
     int d10 = round(i/1000000000) ;
    d10 = d10 % 10 ;
    printf("Tenth digit is\t%i\n", d10);
    
     int d11 = round(i/10000000000) ;
    d11 = d11 % 10 ;
    printf("Eleventh digit is\t%i\n", d11);
    
     int d12 = round(i/100000000000) ;
    d12 = d12 % 10 ;
    printf("Twelveth digit is\t%i\n", d12);
    
     int d13 = round(i/1000000000000) ;
    d13 = d13 % 10 ;
    printf("Thirteenth digit is\t%i\n", d13);
    
     int d14 = round(i/10000000000000) ;
    d14 = d14 % 10 ;
    printf("Fourteenth digit is\t%i\n", d14);
    
     int d15 = round(i/100000000000000) ;
    d15 = d15 % 10 ;
    printf("Fifteenth digit is\t%i\n", d15);
    
     int d16 = round(i/1000000000000000) ;
    d16 = d16 % 10 ;
    printf("Sixteenth digit is\t%i\n", d16);
    
    for(i=2;i<17;1+=2)
    {
        
    }
    
    
}*/