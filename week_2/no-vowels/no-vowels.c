// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./no-vowels word\n");
        return 1;
    }

    string replace(string word);

    printf("%s\n", replace(argv[1]));
}

string replace(string word)
{
    int n = 0;
    while (word[n] != '\0')
    {
        switch (word[n])
        {
            case 'a':
                word[n] = '6';
                break;
            case 'e':
                word[n] = '3';
                break;
            case 'i':
                word[n] = '1';
                break;
            case 'o':
                word[n] = '0';
        }
        n++;
    }
    return word;
}
