#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
Approach: Height Descending + Manual Insertion

Description:
1. Sort people by height in descending order.
2. If heights are equal, sort by k value in ascending order.
3. Iterate and manually insert each person at index = k
   by shifting elements to the right.

Time Complexity: O(n^2)
  - Sorting: O(n log n)
  - Shifting elements: O(n^2) worst case

Space Complexity: O(1)
  - In-place modification
*/

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& arr) {

        // Sort by height descending, if equal height then k ascending
        sort(arr.begin(), arr.end(), [](vector<int> a, vector<int> b){
            if(a[0] == b[0]){
                return a[1] < b[1];
            }
            return a[0] > b[0];
        });

        // Manual insertion based on k value
        for(int i = 1; i < arr.size(); i++){
            int pos = arr[i][1];
            vector<int> temp = arr[i];
            int j = i;

            // Shift elements right until correct position
            while(j > pos){
                arr[j] = arr[j - 1];
                j--;
            }
            arr[pos] = temp;
        }

        return arr;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> test1 = {{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
    vector<vector<int>> test2 = {{6,0},{5,0},{4,0},{3,2},{2,2},{1,4}};

    auto res1 = obj.reconstructQueue(test1);
    auto res2 = obj.reconstructQueue(test2);

    cout << "Test Case 1:\n";
    for(auto &p : res1){
        cout << "[" << p[0] << "," << p[1] << "] ";
    }

    cout << "\n\nTest Case 2:\n";
    for(auto &p : res2){
        cout << "[" << p[0] << "," << p[1] << "] ";
    }

    return 0;
}