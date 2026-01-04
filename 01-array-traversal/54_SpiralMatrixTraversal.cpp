
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if (matrix.size() == 0) return ans;
        int tr=0,br=matrix.size()-1,lc=0,rc=matrix[0].size()-1;  
        while(tr<=br && lc<=rc){
            //print top row
            for(int i=lc;i<=rc;i++){
                ans.push_back(matrix[tr][i]);  
            }
            //print right column
            for(int i=tr+1;i<br;i++){
                ans.push_back(matrix[i][rc]);  
            }
            //print bottom row
            if(tr!=br){
                for(int i=rc;i>=lc;i--){
                    ans.push_back(matrix[br][i]);  
                }
            }
            //print left column
            if(lc!=rc){
                for(int i=br-1;i>=tr+1;i--){
                    ans.push_back(matrix[i][lc]);  
                }}
            tr++; rc--;br--;lc++;
        }
        return ans;
    }
};


int main() {
    Solution sol;

    // 2D vector syntax:
    // vector<vector<int>> name = { {row1}, {row2}, ... };

    vector<vector<int>> matrix = {
        { 1,  2,  3,  4,  5,  6,  7},
        { 8,  9, 10, 11, 12, 13, 14},
        {15, 16, 17, 18, 19, 20, 21},
        {22, 23, 24, 25, 26, 27, 28},
        {29, 30, 31, 32, 33, 34, 35}
    };

    vector<int> result = sol.spiralOrder(matrix);

    // Traversing 1D vector
    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}

    