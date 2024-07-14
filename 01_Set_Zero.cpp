#include <vector>
#include <iostream>

using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
           int n = matrix.size();    // Number of rows
        if (n == 0) return;       // Handle empty matrix
        int m = matrix[0].size(); // Number of columns

        // Create arrays with dynamic memory allocation
        int *col = new int[m]();
        int *row = new int[n]();

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(matrix[i][j] == 0)
                {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(row[i] || col[j])
                {
                    matrix[i][j] = 0;
                }
            }
        }

        // Free dynamically allocated memory
        delete[] col;
        delete[] row;
}

int main() {
    vector<vector<int>> matrix = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    setZeroes(matrix);
    
    for (const auto& row : matrix) {
        for (const auto& elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }
    
    return 0;
}
