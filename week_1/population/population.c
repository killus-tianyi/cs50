#include <cs50.h>
#include <stdio.h>

int get_start(void);
int get_end(int start);
int calculate(int start, int end);

int main(void)
{
    //Prompt for start size
    int strt_pop = get_start();

    //Prompt for end size
    int end_pop = get_end(start);

    //Calculate number of years until we reach threshold
    int year = calculate(strt_pop, end_pop);

    //Print number of years
    printf("Years: %d", year);
}

int get_start(void)
{
    int i;
    do
    {
        i = get_int("Start size: ");
    }
    while (i < 9);
    return i;
}

int get_end(int start)
{
    int i;
    do
    {
        i = get_int("End size: ");
    }
    while (i < start);
    return i;
}

int calculate(int start, int end)
{
    int current_population = start;
    int year = 0;
    while (current_population < end)
    {
        current_population = current_population + current_population / 3 - current_population / 4;
        year++;
    }
    return year;
}