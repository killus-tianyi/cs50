#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

string encryt(string text, string key);
bool is_valid(string key);

int main(int argc, string argv[])
{
    // check the input key is valid
    if (argc !=  2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    if (!is_valid(argv[1]))
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    //receive the plaintext from user
    string plaintext = get_string("plaintext:  ");

    // encryt the plaintext and print it in screen
    string cipertext = encryt(plaintext, argv[1]);

    printf("ciphertext: %s\n", cipertext);
    return 0;
}

string encryt(string text, string key)
{
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isalpha(text[i]))
        {
            if (isupper(text[i]))
            {
                text[i] = toupper(key[text[i] - 'A']);
            }
            else
            {
                text[i] = tolower(key[text[i] - 'a']);
            }
        }
    }
    return text;
}

bool is_valid(string key)
{
    int len = strlen(key);

    if (len != 26)
    {
        return false;
    }

    for (int i = 0; i < len; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (!isalpha(key[i]) || key [i] == key[j])
            {
                return false;
            }
        }
    }

    return true;
}
