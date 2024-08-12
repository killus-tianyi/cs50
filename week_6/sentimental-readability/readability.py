def main():
    text = input("Text: ")
    letter = calculate_letter(text)
    word = text.count(" ") + 1
    sentence = text.count(".") + text.count("?") + text.count("!")

    index =  round(float(letter) / word * 100 * 0.0588 - sentence / float(word) * 100 * 0.296 - 15.8)

    if index >= 16:
        print("Grade 16+")
    elif (index < 1):
        print("Before Grade 1")
    else:
        print(f"Grade {index}")

def calculate_letter(n):
    count = 0
    length = len(n)
    for i in range(length):
        if n[i].isalpha():
            count += 1
    return count

main()
