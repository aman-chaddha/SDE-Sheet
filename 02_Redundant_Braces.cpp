#include <iostream>
#include <stack>
#include <string>
using namespace std;

int checkRedundantBraces(string A) {
    stack<char> s;

    // Traverse each character in the string A
    for (char c : A) {
        // If the current character is a closing bracket ')'
        if (c == ')') {
            char top = s.top();  // Get the top element of the stack
            s.pop();  // Remove the top element from the stack
            bool flag = true;  // Initialize a flag to check for operators

            // Check characters inside the current pair of parentheses
            while (!s.empty() && top != '(') {
                // If we find an operator, the braces are not redundant
                if (top == '+' || top == '-' || top == '*' || top == '/') {
                    flag = false;
                }
                top = s.top();  // Get the new top element
                s.pop();  // Remove the top element
            }
            // If no operator found, braces are redundant
            if (flag) {
                return 1;
            }
        } else {
            // Push current character to stack
            s.push(c);
        }
    }

    // No redundant braces found
    return 0;
}

int main() {
    // Test cases
    string A1 = "((a+b))";
    string A2 = "(a+(a+b))";
    string A3 = "((a*b)+(c+d))";

    cout << checkRedundantBraces(A1) << endl; // Output: 1
    cout << checkRedundantBraces(A2) << endl; // Output: 0
    cout << checkRedundantBraces(A3) << endl; // Output: 0

    return 0;
}
