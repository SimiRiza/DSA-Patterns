/*
Approach: Sliding Window
- First, count customers already satisfied (grumpy[i] == 0)
- Then use a window of size `minutes` to maximize extra satisfied customers
- Slide window and keep track of max additional customers
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int>& cust, vector<int>& grumpy, int minutes) {
        int sum = 0;

        // Already satisfied customers
        for (int i = 0; i < cust.size(); i++) {
            if (grumpy[i] == 0)
                sum += cust[i];
        }

        int max_inwindow = 0, max_inarray = 0;
        int start = 0, end = 0;

        // First window
        while (end < minutes) {
            if (grumpy[end] == 1)
                max_inwindow += cust[end];
            end++;
        }

        // Sliding window
        while (end < cust.size()) {
            max_inarray = max(max_inarray, max_inwindow);

            if (grumpy[end] == 1)
                max_inwindow += cust[end];

            if (grumpy[start] == 1)
                max_inwindow -= cust[start];

            start++;
            end++;
        }

        max_inarray = max(max_inarray, max_inwindow);

        return max_inarray + sum;
    }
};

// Minimal main with test cases
int main() {
    Solution sol;

    vector<int> customers = {1,0,1,2,1,1,7,5};
    vector<int> grumpy =   {0,1,0,1,0,1,0,1};
    int minutes = 3;

    cout << sol.maxSatisfied(customers, grumpy, minutes) << endl; // Expected: 16

    return 0;
}