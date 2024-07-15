#include<iostream>
#include<vector>

using namespace std;

int countLessThanOrEqual(vector<int>& A, int B){
    int left = 0, right = A.size()-1;
    int count = 0;

    while(left<=right){
        int mid = left + (right-left)/2;
        if(A[mid]<=B){
            count = mid+1;
            left = mid+1;
        } else {
            right = mid-1;
        }
    }
    return count;
}

int main() {
    vector<int> A1 = {1, 3, 4, 4, 6};
    int B1 = 4;
    cout << countLessThanOrEqual(A1, B1) << endl; // Output: 4

    vector<int> A2 = {1, 2, 5, 5};
    int B2 = 3;
    cout << countLessThanOrEqual(A2, B2) << endl; // Output: 2

    return 0;
}