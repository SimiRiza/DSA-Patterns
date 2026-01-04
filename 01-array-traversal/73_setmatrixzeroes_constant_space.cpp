#include <vector>
#include <iostream>
using namespace std;
int main() {
    int m = 3;
    int n = 4;
 vector<vector<int>> matrix = {
        { 1,  2,  0,  6},
        { 0,  6, 0, 1},
        {7, 2, 1, 3}
    };
        
        // Second pass:
        // Set matrix elements to zero if their row or column is marked
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        //print matrix
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

