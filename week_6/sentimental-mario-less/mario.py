
def main():
    Height = get_int()

    print_pyramid(Height)


def get_int():
    n = input("Height: ")
    while (not n.isdigit() or int(n) < 1 or int(n) > 8):
        n = input("Height: ")
    return int(n)


def print_pyramid(n):
    for i in range(n):
        for j in range(n):
            if i + j >= n - 1:
                print("#", end="")
            else:
                print(" ", end="")
        print()


main()
