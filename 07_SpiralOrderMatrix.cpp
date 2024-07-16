#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> generateMatrix(int A){
    vector<vector<int>> matrix(A, vector<int>(A,0));

    int top = 0, bottom = A-1;
    int left = 0, right = A-1;
    int num = 1;

    while(top<=bottom && left<=right){
        for(int i = left; i<=right; i++){
            matrix[top][i] = num++; 
        } top++;


        for(int i = top; i<=bottom; i++){
            matrix[i][right] = num++;
        }
        right--;

        if (top <= bottom) {
            for (int i = right; i >= left; --i) {
                matrix[bottom][i] = num++;
            }
            bottom--;
        }
        
        // Fill left column from bottom to top
        if (left <= right) {
            for (int i = bottom; i >= top; --i) {
                matrix[i][left] = num++;
            }
            left++;
        }
    }
    
    return matrix;
}


int main() {
    int A;
    cin >> A;

    vector<vector<int>> result = generateMatrix(A);

    for (const auto& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}