#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "wav.h"

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    // TODO #1
    if (argc != 3)
    {
        printf("./reverse input.wav output.wav\n");
        return 1;
    }

    // Open input file for reading
    // TODO #2
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("can not open this file\n");
        return 1;
    }


    // Read header
    // TODO #3
    WAVHEADER header;
    fread(&header, sizeof(header), 1, input);


    // Use check_format to ensure WAV format
    // TODO #4
    if (!check_format(header))
    {
        printf("this file is not the .wav file\n");
        return 2;
    }

    // Open output file for writing
    // TODO #5
    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("can not open the file\n");
        return 3;
    }

    // Write header to file
    // TODO #6
    fwrite(&header, sizeof(header), 1, output);

    // Use get_block_size to calculate size of block
    // TODO #7
    BYTE size_of_block = get_block_size(header);

    // Write reversed audio to file
    // TODO #8
    BYTE buffer[size_of_block];
    fseek(input, -sizeof(buffer), SEEK_END);
    while (ftell(input) >= sizeof(header))
    {
        fread(buffer, sizeof(buffer), 1, input);
        fwrite(buffer, sizeof(buffer), 1, output);
        fseek(input, -2 *sizeof(buffer), SEEK_CUR);
    }
    fclose(input);
    fclose(output);
    return 0;
}

int check_format(WAVHEADER header)
{
    // TODO #4
   char checkID[] = {'R', 'I', 'F', 'F'};
   char checkID1[] = {'f', 'm', 't', ' '};
   char checkID2[] = {'d', 'a', 't', 'a'};
   if (header.chunkSize == 20 + header.subchunk1Size + header.subchunk2Size && header.byteRate == header.sampleRate * header.numChannels * header.bitsPerSample / 8 && header.blockAlign == header.numChannels * header.bitsPerSample / 8)
   {
    for (int i = 0; i < 4; i++)
    {
        if (checkID[i] != header.chunkID[i] || checkID2[i] != header.subchunk2ID[i] || header.subchunk1ID[i] != checkID1[i])
        {
            break;
        }
    }
    return 1;
   }
    return 0;
}

int get_block_size(WAVHEADER header)
{
    // TODO #7
    BYTE blocksize = header.numChannels * header.bitsPerSample / 8;
    return blocksize;
}
