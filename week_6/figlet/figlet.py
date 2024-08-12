import sys
from pyfiglet import Figlet
import random


figlet = Figlet()
font_lst = figlet.getFonts()
selected_font = random.choice(font_lst)

def main():
    global selected_font

    if not is_valid():
        sys.exit("Invalid usage")

    origin = input("Input: ")
    figlet.setFont(font = selected_font)
    print(figlet.renderText(origin))

def is_valid():
    global selected_font

    #check the length limit
    input_len = len(sys.argv)
    if (input_len != 1 and input_len != 3):
        return False

    # isvalid when user supply the selected information
    if input_len == 3:
        if not ((sys.argv[1] == "-f" or sys.argv[1] == "--font" ) and sys.argv[2] in font_lst):
            return False
        else:
            selected_font = sys.argv[2]

    return True

main()
