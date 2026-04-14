#include <iostream>
#include <string>

/*
 * Function: harmonic
 * -------------------
 * Recursively calculates the nth harmonic number:
 * H_n = 1 + 1/2 + 1/3 + ... + 1/n
 *
 * Base case: n == 1
 * Recursive case: H_n = 1/n + H_(n-1)
 */
double harmonic(int n) {
    if (n == 1)
        return 1.0;
    return (1.0 / n) + harmonic(n - 1);
}

/*
 * Function: isPalindrome
 * ----------------------
 * Recursively checks if a string is a palindrome.
 *
 * Base cases:
 * - If string length is 0 or 1 → palindrome
 *
 * Recursive case:
 * - Check first and last characters
 * - Recurse on the substring without them
 */
bool isPalindrome(std::string str) {
    if (str.length() <= 1)
        return true;

    if (str[0] != str[str.length() - 1])
        return false;

    // Recursive call on smaller substring
    return isPalindrome(str.substr(1, str.length() - 2));
}

/*
 * Function: printTriangle
 * -----------------------
 * Recursively prints a triangle of height n:
 *
 * *
 * **
 * ***
 * ...
 *
 * Base case: n == 0 (do nothing)
 * Recursive case:
 * - First print triangle of size n-1
 * - Then print current row of n stars
 */
void printTriangle(int n) {
    if (n == 0)
        return;

    printTriangle(n - 1);

    for (int i = 0; i < n; i++) {
        std::cout << "*";
    }
    std::cout << std::endl;
}

int main() {
    // ---- Harmonic Number ----
    int n;
    std::cout << "Enter an integer for harmonic number: ";
    std::cin >> n;
    std::cout << "Harmonic number H_" << n << " = " << harmonic(n) << std::endl;

    // ---- Palindrome Check ----
    std::string word;
    std::cout << "\nEnter a string to check palindrome: ";
    std::cin >> word;

    if (isPalindrome(word))
        std::cout << word << " is a palindrome." << std::endl;
    else
        std::cout << word << " is NOT a palindrome." << std::endl;

    // ---- Triangle Printing ----
    int height;
    std::cout << "\nEnter height for triangle: ";
    std::cin >> height;

    std::cout << std::endl;
    printTriangle(height);

    return 0;
}
