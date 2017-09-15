/**
 * Copies a BMP piece by piece, just because.
 */
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4 )
    {
        fprintf(stderr, "Usage: ./copy n infile outfile\n");
        fprintf(stderr, "Where n is a positive integer less than or equal to 100,\n");
        fprintf(stderr, "infile is the name of BMP to be resized,\noutfile is the output file to store the new BMP\n");
        return 1;
    }
    
     // remember filenames
    char *infile = argv[2];
    char *outfile = argv[3];
    int n = atoi(argv[1]);
    
    if(n <= 0 || n > 100)
    {
        fprintf(stderr, "Usage: ./copy n infile outfile\n");
        fprintf(stderr, "Where n is a positive integer less than or equal to 100,\n");
        fprintf(stderr, "infile is the name of BMP to be resized,\n outfile is the output file to store the new BMP\n");
        return 1;
    }



    // open input file 
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }
    
        // determine padding for scanlines
    int in_padding = ((4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4);
    int out_padding = ((4 - (bi.biWidth * n * sizeof(RGBTRIPLE)) % 4) % 4);
    
//    printf("biWidth is %i biHeight is %i biSize is %i Inpadding is %i Outpad is %i \n", bi.biWidth, bi.biHeight, bi.biSizeImage, in_padding, out_padding );

    // write outfile's BITMAPFILEHEADER
    bi.biWidth *=n;
    bi.biHeight *= n; 
    bi.biSizeImage = ( ( ( sizeof(RGBTRIPLE) * bi.biWidth ) + out_padding) * abs(bi.biHeight) ) ;
    bf.bfSize = bi.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) ;
    
//    printf("biWidth is %i biHeight is %i biSize is %i Inpadding is %i Outpad is %i \n", bi.biWidth, bi.biHeight, bi.biSizeImage, in_padding, out_padding );
    
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        int vert_size = n;
        // iterate over pixels in scanline
        while(vert_size != 0)
        {
            for (int j = 0; j < bi.biWidth; j++)
            {
                int hor_size = 0;
                hor_size = n;
                // temporary storage
                RGBTRIPLE triple;
    
                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
    
                // write RGB triple to outfile
                while(hor_size!=0)
                {
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                    n -- ;
                    j++;
                }
            }
      
    
            // then add it back (to demonstrate how)
            for (int k = 0; k < out_padding; k++)
            {
                fputc(0x00, outptr);
            }
            vert_size -- ;
            i++;
        }
              // skip over padding, if any
            fseek(inptr, in_padding, SEEK_CUR);
            
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0; 
}
