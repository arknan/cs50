#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

int main(int argc, char *argv[])
{
    if ( argc != 2 )
    {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if ( file == NULL )
    {
        fprintf(stderr, "Could not open file %s\n", argv[1]);
        return 2;
    }

    uint8_t buffer[512] ;
    int filenumber = 0;
    char filename[8] ;

    FILE *img = NULL ;

    while (1)
    {
        if (fread (buffer, 1, 512, file) > 0)
        {
            if ( buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && 
            ( (buffer[3] & 0xf0) == 0xe0))
            {
                if ( img == NULL )
                {
                    sprintf(filename, "%03i.jpg", filenumber) ;
                    filenumber ++ ;
                    
                    img = fopen(filename, "w");
                    fwrite(buffer, 1, 512, img);
                }
                else
                {
                    fclose(img);
                    sprintf(filename, "%03i.jpg", filenumber) ;
                    filenumber ++ ;
                    img = fopen(filename, "w");
                    fwrite(buffer, 1, 512, img);
                }
            }
            else
            {
                if ( img != NULL)
                {
                    fwrite(buffer, 1, 512, img);
                }
            }
        }
        else
        {
            fclose(img) ;
            fclose(file);
            return 0;
        }
    }
}
