// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    // the valid_array : upper, low, num, symb
    bool valid_array[4] = {false};
    int i = 0;
    while (password[i] != '\0')
    {
        if (isupper(password[i]))
        {
            valid_array[0] = true;
        }
        else if (islower(password[i]))
        {
            valid_array[1] = true;
        }
        else if (isdigit(password[i]))
        {
            valid_array[2] = true;
        }
        else
        {
            valid_array[3] = true;
        }
        i++;
    }

    for (int j = 0; j < 4; j++)
    {
        if (valid_array[j] == false)
        {
            return false;
        }
    }
    return true;
}
