// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26 * 26;

// Hash table
node *table[N];


// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    unsigned int index = hash(word);
    node *ptr = table[index];

    // try to iterate the link list
    while (ptr != NULL)
    {
        if (strcasecmp(word, ptr->word) == 0)
        {
            return true;
        }

        ptr = ptr->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    unsigned int second = 0;
    if (word[1] != '\0')
    {
        second = toupper(word[1]) - 'A';
    }

    return (toupper(word[0]) - 'A') * 26 + second;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *infile = fopen(dictionary, "r");
    if (infile == NULL)
    {
        printf("can not load the file\n");
        return false;
    }

    // store the word every line and create the new node
    char word[LENGTH + 1];

    while (fscanf(infile, "%s", word) == 1)
    {
        // create a new node
        node *new = malloc(sizeof(node));
        if (new == NULL)
        {
            printf("can not load the file\n");
            return false;
        }

        strcpy(new -> word, word);
        new -> next = NULL;

        // find the index of the word in hash table
        unsigned index = hash(word);

        // determine wheather there is a node in the table[index]
        if (table[index] == NULL)
        {
            table[index] = new;
            continue;
        }


        // load the new node into the hash table
        node *ptr = table[index];

        // let the ptr point to the last element in the every link list
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr -> next = new;
    }

    // close the input file
    fclose(infile);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    unsigned count = 0;
    // TODO
    for (int i = 0; i < N; i++)
    {
        node *ptr = table[i];
        while (ptr != NULL)
        {
            ptr = ptr->next;
            count++;
        }
    }
    return count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    node *ptr = NULL;
    for (int i = 0; i < N; i++)
    {
        ptr = table[i];
        while (ptr != NULL)
        {
            node *next = ptr->next;
            free(ptr);
            ptr = next;
        }
    }
    return true;
}
