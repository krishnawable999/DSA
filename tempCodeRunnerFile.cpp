#include <iostream>
#include <string>

using namespace std;

// Function to convert the given string to a binary string based on character groups
void convertToBinaryString(const string& str1) {
    string result = "";
    for (char ch : str1) {
        // Determine the binary value based on the character group
        if (ch >= 'a' && ch <= 'e') {
            result += '0';
        } else if (ch >= 'f' && ch <= 'j') {
            result += '1';
        } else if (ch >= 'k' && ch <= 'o') {
            result += '0';
        } else if (ch >= 'p' && ch <= 't') {
            result += '1';
        } else if (ch >= 'u' && ch <= 'y') {
            result += '0';
        } else if (ch == 'z') {
            result += '1';
        }
    }
    // Output the resultant binary string
    cout << result << endl;
}

int main() {
    string str1;
    // Read the input string from STDIN
    cin >> str1;
    // Convert the string to a binary string and display the result
    convertToBinaryString(str1);
    return 0;
}