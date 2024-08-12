#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);
void detobi(char letter, int array[]);

int main(void)
{
    // receive the user input
    string text = get_string("Message: ");

    // translate every letter into a 8-bit array and then print it
    for (int i = 0, len = strlen(text);i < len; i++)
    {
        int binary_code[BITS_IN_BYTE] = {0};
        detobi(text[i], binary_code);

        for (int j = 0; j < BITS_IN_BYTE; j++)
        {
            print_bulb(binary_code[j]);
        }
        printf("\n");
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}

void detobi(char letter, int array[])
{
    for (int i = 0; letter != 0; i++)
    {
        if (letter % 2  == 1)
        {
            array[BITS_IN_BYTE - i - 1] = 1;
        }
        letter /= 2;
    }
}
