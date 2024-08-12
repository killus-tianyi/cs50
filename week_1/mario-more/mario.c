#include <cs50.h>
#include <stdio.h>

void print_pyramids(int n);
int get_height(void);

int main(void)
{
   //prompt a positive number bewteen 1 and 9
   int n = get_height();

   //create the specified height pyramids
   print_pyramids(n);

}

void print_pyramids(int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n + i + 3; j++)
        {
            if (j < n - i -1 || (j > n -1 && j < n + 2))
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        printf("\n");
    }
}

int get_height(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);
    return n;
}