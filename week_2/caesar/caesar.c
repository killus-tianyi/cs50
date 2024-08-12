#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    bool only_digit(string text);
    string encrytion(string plaintext, int key);

    // confirm that the input value is vaild
    if (argc != 2 || !only_digit(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    string plaintext = get_string("plaintext: ");

    //transfer the plaintext into ciphertext
    string cipertext = encrytion(plaintext, atoi(argv[1]));

    //print out the ciphertext
    printf("ciphertext: %s\n", cipertext);
    return 0;
}

bool only_digit(string text)
{
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (!isdigit(text[i]))
        {
            return false;
        }
    }
    return true;
}

string encrytion(string plaintext, int key)
{
    for (int i = 0; plaintext[i] != '\0'; i++)
    {
        char letter = plaintext[i];
        if (isalpha(letter))
        {
            if (isupper(letter))
            {
                plaintext[i] = 'A' + (letter - 'A' + key) % 26;
            }
            else
            {
                plaintext[i] = 'a' + (letter - 'a' + key) % 26;
            }
        }
    }
    return plaintext;
}
