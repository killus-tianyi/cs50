import re
def main():
    user_input = input("Number: ")

    length = len(user_input)

    if(through_luhn(user_input)):
        if (length == 13 or length == 16) and user_input.startswith('4'):
            print("VISA")
            return
        elif length == 16 and re.search('^5[1-5][0-9]*$', user_input):
            print("MASTERCARD")
            return
        elif length == 15 and (user_input.startswith("34") or user_input.startswith("37")):
            print("AMEX")
            return
    print("INVALID")

def through_luhn(n):
    sum = 0
    length = len(n)
    for i in range(length - 2, -1, -2):
        digit = int(n[i])
        if (digit > 4):
            sum += (digit * 2 - 9)
        else:
            sum += (2 * digit)

    for j in range(length - 1, -1, -2):
        sum += int(n[j])
    return not (sum % 10)


main()

