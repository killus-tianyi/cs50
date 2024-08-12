import csv
import sys

genes = []
genes_table = [0, 0, 0, 0, 0, 0, 0, 0]



def main():
    global genes
    global genes_table

    database = []
    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py data.csv sequence.txt")

    # TODO: Read database file into a variable
    with open(sys.argv[1]) as file:
        reader = csv.DictReader(file)
        for row in reader:
            database.append(row)
    # get the all the key into to list
    genes = list(database[0].keys())



    # TODO: Read DNA sequence file into a variable
    file2 = open(sys.argv[2], 'r')
    dna = file2.readline()

    # TODO: Find longest match of each STR in DNA sequence
    for i in range(len(genes)):
        genes_table[i] = longest_match(dna, genes[i])


    # TODO: Check database for matching profiles
    for row in database:
        print(row)
        if (is_inside(row, genes_table)):
            print(row["name"])
            return 0

    print("No match")


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run

def is_inside(dict, table):
    global genes
    for i in range(len(genes)):
        if (dict[genes[i]] != str(table[i])):
            return False
    return True
main()
