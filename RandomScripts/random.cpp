#include <iostream>
#include <cctype>
#include <algorithm>
using namespace std;

/**
 * Reverses a given string and prints the reversed string along with its last character.
 * @param input The string to be reversed.
 */
void reverse(string input) {
    string reversed_input = input;
    reverse(reversed_input.begin(), reversed_input.end());
    cout << reversed_input << endl;
    cout << reversed_input[reversed_input.size() - 1] << endl;
}

/**
 * Checks if a given string is a palindrome, ignoring non-alphabetic characters.
 * A palindrome reads the same forward and backward.
 * @param input The string to check.
 * @return True if the string is a palindrome, False otherwise.
 */
bool palindrome(const string& input) {
    for (int i = 0; i < input.size(); i++) {
        if (!isalpha(input[i])) return false;
    }
    string reversed_input = input;
    reverse(reversed_input.begin(), reversed_input.end());
    return input == reversed_input;
}

/**
 * Removes all spaces from a given string.
 * @param input The string from which spaces are to be removed.
 * @return A new string with all spaces removed from the input.
 */
string del_space(const string& input) {
    string new_input = input; 
    new_input.erase(remove(new_input.begin(), new_input.end(), ' '), new_input.end());
    return new_input; 
}

/**
 * Validates the basic format of an address.
 * This function is still in progress and currently checks for a specific format.
 * @param input The address string to validate.
 * @return True if the address format is valid, False otherwise.
 */
bool validate_adress3(const string& input) {
    string address = del_space(input);
    if (address.size() > 80 || address[3] != ',') return false;
    for (int i = 0; i < 3; i++) {
        if (!isdigit(address[i])) return false;
    }
    for (int i = 0; i < address.size(); i++) {
        if (!isalpha(address[i])) return false;
    }
    return true;
}

/**
 * Validates the format of a Canadian postal code.
 * @param in The postal code to validate.
 * @return True if the format is valid, False otherwise.
 */
bool validate_PostalCode(const string& in) {
    string input = del_space(in);
    if (input.size() != 6) return false;
    for (int i = 0; i < input.size(); i += 2) {
        if (!isupper(input[i]) || !isdigit(input[i + 1])) return false;
    }
    return true;
}

int main() {
    // Test cases for the functions.
    if (palindrome("madam")) cout << "Succès" << endl;
    if (validate_PostalCode("G1V 2T6")) cout << "Succès" << endl;
    if (!validate_PostalCode("g1V 2T6")) cout << "Succès" << endl;
    if (validate_adress3("936,rue Paradis")) cout << "Succès" << endl;

    return 0;
}
