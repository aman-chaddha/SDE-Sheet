#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;

int maxProductOfThree(vector<int>& A){
    int n = A.size();

    sort(A.begin(), A.end());
    int max1 = A[n-1]*A[n-2]*A[n-3];
    int max2 = A[0]*A[1]*A[n-1];
    return max(max1,max2);
}


int main() {
    vector<int> A1 = {1, 2, 3, 4};
    vector<int> A2 = {0, -1, 3, 100, 70, 50};
    
    cout << maxProductOfThree(A1) << endl; // Output: 24
    cout << maxProductOfThree(A2) << endl; // Output: 350000
    
    return 0;
}