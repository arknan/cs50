#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char *infile = argv[2];
    char *outfile = argv[3];
    int n = atoi(argv[1]);
    
    if(argc !=4 || n > 100)
    {
        fprintf(stderr, "Usage : ./resize n infile outfile\n");
        fprintf(stderr, "Where n is a positive integer less than or equal to 100,\n");
        fprintf(stderr, "infile is the name of BMP to be resized,\n outfile is the output file to store the new BMP\n");
        return 1;
    }
    

    
    
    
    return 0;
}