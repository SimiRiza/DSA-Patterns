/*
Approach: Descending Sort + Linear Traversal

Sort the array in descending order.
Traverse once and whenever a strictly smaller element is found,
add (current index + 1) to the count.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());

        int curr = 0, nxt = 1, count = 0;

        while (nxt < nums.size()) {
            if (nums[curr] > nums[nxt]) {
                count = count + curr + 1;
            }
            nxt++;
            curr++;
        }

        return count;
    }
};

int main() {
    Solution sol;

    vector<int> test1 = {5, 1, 3};
    vector<int> test2 = {1, 1, 1};

    cout << sol.reductionOperations(test1) << endl;
    cout << sol.reductionOperations(test2) << endl;

    return 0;
}