#include<stdio.h>

void print(int i[]);
void sort(int i[]);

int main(void)
{
    int i[5] = {9,3,5,7,6};
    printf("Array before sorting is\n");
    print(i);
    
    sort(i);
    
    printf("Array after sorting is\n");
    print(i);
}

void print(int i[])
{
    for(int j=0;j<5;j++)
    {
        printf("%i", i[j]);
    }
}

void sort(int i[])
{
    int temp =0;
    for(int j=0;j<5;j++)
    {
        for(int k=j+1;k<5;k++)
        {
            if(i[j] > i[k])
            {
                temp = i[k];
                i[k]=i[j];
                i[j]=temp;
            }
        }
    }
}