#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    int calculate_level(int letter, int word, int sentence);
    int count_sentences(string text);
    int count_words(string text);
    int count_letters(string text);

    //get the raw data from user
    string text = get_string("Text: ");

    int letter = count_letters(text);
    int word = count_words(text);
    int sentence = count_sentences(text);
    int index = calculate_level(letter, word, sentence);
    printf("%d\n", word);
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

// calculate the number of letter in a paragraph
int count_letters(string text)
{
    int count = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isalpha(text[i]))
        {
            count++;
        }
    }
    return count;
}

// calculate the number of word in a paragraph
int count_words(string text)
{
    int count = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == ' ')
        {
            count++;
        }
    }
    return count + 1;
}

//calculate the number of sentence in a paragraph
int count_sentences(string text)
{
    int count = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count++;
        }
    }
    return count;
}

// calulate the raw index of reading level
int calculate_level(int letter, int word, int sentence)
{
    float index = letter / (float)word * 100 * 0.0588 - sentence / (float)word * 100 * 0.296 - 15.8;
    return (int)round(index);
}

