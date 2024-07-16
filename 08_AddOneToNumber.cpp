#include <vector>
#include <iostream>

using namespace std;

vector<int> addOne(vector<int>& digits) {
    int n = digits.size();

    // Remove leading zeros
    int index = 0;
    while (index < n && digits[index] == 0) {
        index++;
    }

    if (index == n) {
        return {1};  // Edge case where all digits are 0
    }

    // If there were leading zeros, work with the trimmed vector
    vector<int> trimmedDigits(digits.begin() + index, digits.end());

    // Process the digits from the least significant digit
    n = trimmedDigits.size();
    for (int i = n - 1; i >= 0; --i) {
        if (trimmedDigits[i] < 9) {
            trimmedDigits[i]++;
            return trimmedDigits;
        }
        trimmedDigits[i] = 0;
    }

    // If we finished the loop and haven't returned, there was a carry over
    trimmedDigits.insert(trimmedDigits.begin(), 1);
    return trimmedDigits;
}

int main() {
    vector<vector<int>> testCases = {
        {1, 2, 3},
        {0, 1, 2, 3},
        {9, 9, 9},
        {0, 0, 0},
        {0, 3, 7, 6, 4, 0, 5, 5, 5}
    };

    for (auto& test : testCases) {
        vector<int> result = addOne(test);
        for (int digit : result) {
            cout << digit << " ";
        }
        cout << endl;
    }

    return 0;
}
