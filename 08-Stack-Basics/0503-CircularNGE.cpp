/*
Approach: Monotonic Stack (Circular Array)
Description:
- Traverse from right to left for 2*n iterations to simulate circular behavior.
- Maintain a decreasing stack.
- Remove smaller or equal elements since they can never become the next greater element.
- For the actual array pass (i < n), store the stack top as answer.

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();

        // Result initialized with -1 (default if no next greater exists)
        vector<int> res(n, -1);

        // Monotonic decreasing stack storing values
        stack<int> st;

        int idx;

        // Traverse twice to simulate circular array
        for(int i = 2*n - 1; i >= 0; i--) {

            // Convert virtual index into real array index
            if(i > n - 1)
                idx = i % n;
            else
                idx = i;

            // Remove all smaller/equal elements
            // because they cannot be next greater
            while(!st.empty() && st.top() <= nums[idx]) {
                st.pop();
            }

            // During actual traversal, store answer
            if(!st.empty() && i < n) {
                res[i] = st.top();
            }

            // Push current element for future comparisons
            st.push(nums[idx]);
        }

        return res;
    }
};

int main() {
    Solution obj;

    // Test 1
    vector<int> nums1 = {1,2,1};
    vector<int> ans1 = obj.nextGreaterElements(nums1);

    cout << "Test 1: ";
    for(int x : ans1)
        cout << x << " ";
    cout << endl;

    // Expected: 2 -1 2


    // Test 2
    vector<int> nums2 = {1,2,3,4,3};
    vector<int> ans2 = obj.nextGreaterElements(nums2);

    cout << "Test 2: ";
    for(int x : ans2)
        cout << x << " ";
    cout << endl;

    // Expected: 2 3 4 -1 4

    return 0;
}
