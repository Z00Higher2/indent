def remove_leading_spaces(line):
    index = 0

    # Iterate through the string until a non-space character is found
    while index < len(line) and line[index].isspace():
        index += 1

    # Return the substring without leading spaces
    return line[index:]

# Function to count occurrences of a character in a string
def count_char(line, c):
    count = 0

    # Iterate through the string and count occurrences of the specified character
    for char in line:
        if char == c:
            count += 1

    # Return the count of occurrences
    return count

def main():
    count = 0

    # Read input lines until the end of the file
    try:
        while True:
            line = input()

            # Check if the first non-space character in the line is '}'
            if remove_leading_spaces(line)[0] == '}':
                # Output tabs based on the current count (minus one)
                print('\t' * (count - 1), end='')
            else:
                # Output tabs based on the current count
                print('\t' * count, end='')

            # Update the count based on the occurrences of '{' and '}'
            count -= count_char(line, '}')
            count += count_char(line, '{')

            # Output the line without leading spaces
            print(remove_leading_spaces(line))

    except EOFError:
        pass

if __name__ == "__main__":
    main()
