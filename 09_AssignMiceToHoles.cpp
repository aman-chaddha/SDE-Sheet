#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>  // For abs()

using namespace std;

int minTimeToAssignHoles(vector<int>& A, vector<int>& B) {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int maxTime = 0;
    for (int i = 0; i < A.size(); i++) {
        maxTime = max(maxTime, abs(A[i] - B[i]));
    }
    
    return maxTime;
}

int main() {
    vector<int> A1 = {-4, 2, 3};
    vector<int> B1 = {0, -2, 4};
    
    vector<int> A2 = {-2};
    vector<int> B2 = {-6};
    
    cout << "Test case 1: " << minTimeToAssignHoles(A1, B1) << endl;  // Output: 2
    cout << "Test case 2: " << minTimeToAssignHoles(A2, B2) << endl;  // Output: 4
    
    return 0;
}
