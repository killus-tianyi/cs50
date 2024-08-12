// Practice writing a function to find a max value

#include <cs50.h>
#include <stdio.h>
#include <math.h>

int max(int array[], int n);
void merge_sort(int array[], int n);

int main(void)
{
    int n = 9;
    /*do
    {
        n = get_int("Number of elements: ");
    }
    while (n < 1);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = get_int("Element %i: ", i);
    }
    */

   int arr[] = {3, 3, 23, 4, 6, 32, 6, 7, 8};

    printf("The max value is %i.\n", max(arr, n));

    for (int i = 0; i < 9; i++)
    {
        printf("%d\n", arr[i]);
    }
}

// TODO: return the max value
int max(int array[], int n)
{
    merge_sort(array, n);
    return array[n - 1];
}


void merge_sort(int array[], int n)
{
    if (n == 1)
    {
        return;
    }

    merge_sort(array, n / 2);
    merge_sort(array + n / 2, n - (n / 2));

    int sorting_lst[n];
    int p1= 0;
    int p2 =n / 2;

    for (int i = 0; i < n; i++)
    {
        if (array[p1] < array[p2] || p2 > n - 1)
        {
            sorting_lst[i] = array[p1];
            p1++;
        }
        else if (array[p2] <= array[p1] || p1 > n / 2)
        {
            sorting_lst[i] = array[p2];
            p2++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        array[i] = sorting_lst[i];
    }
}
