import re

def main():
    # receive the input of user charge
    charge  = get_float() * 100

    # check the number of quarters
    quarter_coin = get_quarters(charge)
    charge = charge - 25 * quarter_coin

    # check the number of dimes
    dimes_coin = get_dimes(charge)
    charge = charge - 10 * dimes_coin

    # check the number of nickels
    nickels_coin = get_nickels(charge)
    charge = charge - 5 * nickels_coin

    # check the number of pennies
    pennies_coin = charge

    # print the total number of coin
    print(int(quarter_coin + dimes_coin + nickels_coin + pennies_coin))

def get_float():
    n = input("Change owed: ")
    while (not isnumber(n) or float(n) < 0):
        n = input("Change owed: ")
    return float(n)

def isnumber(n):
    return re.search('^[0-9]+\.?[0-9]*$', n)


def get_quarters(n):
    coin = 0
    while ((coin + 1) * 25 <= n):
        coin += 1

    return coin

def get_dimes(n):
    coin = 0
    while ((coin + 1) * 10 <= n):
        coin += 1

    return coin

def get_nickels(n):
    coin = 0
    while ((coin + 1) * 5 <= n):
        coin += 1

    return coin

main()
