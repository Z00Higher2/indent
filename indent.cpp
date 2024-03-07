// Author: Zuhayer Tashin
// Course: CSCI-135
// Instructor: Tong Yi
// Assignment: Lab 7B
// Write a new program indent.cpp that enhances the program from the previous task. 
// As it reads the input line by line, it should also count the number of open and closed { } in it, 
// and keep track of how many blocks is currently open at the beginning of each line.

#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

// Function to remove leading spaces from a string
string removeLeadingSpaces(string line) {
    int index = 0;

    // Iterate through the string until a non-space character is found
    while (isspace(line[index])) {
        index++;
    }

    // Return the substring without leading spaces
    return line.substr(index);
}

// Function to count occurrences of a character in a string
int countChar(string line, char c) {
    int count = 0;

    // Iterate through the string and count occurrences of the specified character
    for (int i = 0; i < line.length(); i++) {
        if (line[i] == c) {
            count++;
        }
    }

    // Return the count of occurrences
    return count;
}

int main() {
    string line;
    char c;
    int count = 0;

    // Read input lines until the end of the file
    while (getline(cin, line, '\n')) {

        // Check if the first non-space character in the line is '}'
        if (removeLeadingSpaces(line)[0] == '}') {
            // Output tabs based on the current count (minus one)
            for (int i = 0; i < count - 1; i++) {
                cout << "\t";
            }
        } else {
            // Output tabs based on the current count
            for (int i = 0; i < count; i++) {
                cout << "\t";
            }
        }

        // Update the count based on the occurrences of '{' and '}'
        count -= countChar(line, '}');
        count += countChar(line, '{');

        // Output the line without leading spaces
        cout << removeLeadingSpaces(line) << endl;
    }

    return 0;
}