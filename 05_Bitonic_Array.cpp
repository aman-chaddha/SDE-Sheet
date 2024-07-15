#include<iostream>
#include<vector>

using namespace std;

int searchBitonic(vector<int>&A, int B){
    int n = A.size();
    for(int i = 0; i<n; i++){
        if(A[i]==B){
            return i;
        }
    }
    return -1;
}


int main() {
    vector<int> A1 = {3, 9, 10, 20, 17, 5, 1};
    int B1 = 20;
    cout << searchBitonic(A1, B1) << endl; // Output: 3

    vector<int> A2 = {5, 6, 7, 8, 9, 10, 3, 2, 1};
    int B2 = 30;
    cout << searchBitonic(A2, B2) << endl; // Output: -1

    return 0;
}