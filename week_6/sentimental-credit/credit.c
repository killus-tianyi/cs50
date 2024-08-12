#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    bool through_luhn;
    int get_length(long num);
    bool luhn(int length, long credit);

    // get the number of credit card
    long credit = get_long("Number: ");

    // calculate the length of the credit card
    int length = get_length(credit);

    //determine the credit card number is whether comply with luhn's Luhn’s Algorithm
    through_luhn = luhn(length, credit);

    // determine the category of the card
    if (through_luhn)
    {
        if ((length == 13 || length  == 16) && (int)(credit / pow(10, length - 1)) == 4)
        {
            printf("VISA\n");
            return 0;
        }
        else if (length == 16 && (int)(credit / pow(10, length - 2)) > 50 && (int)(credit / pow(10, length - 2)) < 56)
        {
            printf("MASTERCARD\n");
            return 0;
        }
        else if(length == 15 && ((int)(credit / pow(10, length - 2)) == 34 || (int)(credit / pow(10, length - 2)) == 37))
        {
            printf("AMEX\n");
            return 0;
        }
    }

    printf("INVALID\n");
}

int get_length(long num)
{
    int count = 1;
    while (num / 10 != 0)
    {
        count++;
        num = num / 10;
    }
    return count;
}

bool luhn(int length, long credit)
 {
    int sum = 0;
    bool is_odd = 1;
    while(credit != 0)
    {
        int digit = credit % 10;
        credit = credit / 10;

        if (is_odd == true)
        {
            sum += digit;
            is_odd = false;
        }
        else
        {
            if (digit > 4)
            {
                sum = sum + digit * 2 - 9;
            }
            else
            {
                sum += digit * 2;
            }
            is_odd = true;
        }
    }
    return !(sum % 10);
 }
