#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef uint8_t BYTE;
const int BLOCKSIZE = 512;

bool is_new(BYTE buffer[]);

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    // remember filename
    char *infile = argv[1];

    // open the new file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    BYTE buffer[BLOCKSIZE];

    // create the first jpg file
    char file_name[8];
    int i = 0;
    bool first = true;
    FILE *outptr = NULL;

    while(fread(buffer, 1, BLOCKSIZE, inptr) == BLOCKSIZE)
    {
        if (is_new(buffer))
        {
            if (first == false)
            {
                fclose(outptr);
            }

            sprintf(file_name, "%03d.jpg", i);
            outptr = fopen(file_name, "w");
            first = false;
            i++;
        }

        if (first == false)
        {
            fwrite(buffer, sizeof(buffer), 1, outptr);
        }
    }

    fclose(inptr);
    fclose(outptr);
    return 0;
}

bool is_new(BYTE buffer[])
{
    if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff)
    {
        for (int i = 0xe0, n = buffer[3]; i < 0xef + 1; i++)
        {
            if (n == i)
            {
                return true;
            }
        }
    }

    return false;
}
