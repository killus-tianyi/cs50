#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}

int get_cents(void)
{
    // get the user's change owed
    int n;
    do
    {
        n = get_int("Change owed: ");
    }
    while (n < 0);
    return n;
}

int calculate_quarters(int cents)
{
    // 25
    int n = 1;
    while(n * 25 <= cents)
    {
        n++;
    }
    return n - 1;
}

int calculate_dimes(int cents)
{
    // 10
    int n = 1;
    while(n * 10 <= cents)
    {
        n++;
    }
    return n - 1;
}

int calculate_nickels(int cents)
{
    // 5
    int n = 1;
    while(n * 5 <= cents)
    {
        n++;
    }
    return n - 1;
}

int calculate_pennies(int cents)
{
    // 1
    int n = 1;
    while(n * 1 <= cents)
    {
        n++;
    }
    return n - 1;
}
