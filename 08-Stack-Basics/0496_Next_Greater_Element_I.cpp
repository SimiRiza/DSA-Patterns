/*
Approach: Monotonic Decreasing Stack + Hash Map

Description:
- Traverse nums2 from right to left
- Remove all smaller/equal elements from stack
- Stack top becomes next greater element
- Store mapping in hash map for O(1) lookup
*/

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int,int> mp;
        vector<int> v;

        for(int i = nums2.size()-1; i>=0; i--){

            // Self note:
            // No need for found flag:
            // after removing smaller elements, top itself is answer

            while(!st.empty() && st.top() <= nums2[i]){
                st.pop();
            }

            // If stack empty → no greater element exists
            if(st.empty())
                mp[nums2[i]] = -1;
            else
                mp[nums2[i]] = st.top();

            // Add current element for future comparisons
            st.push(nums2[i]);
        }

        // Build answer using O(1) map lookup
        for(int num : nums1){
            v.push_back(mp[num]);
        }

        return v;
    }
};

int main() {
    Solution s;

    // Test 1
    vector<int> nums1 = {4,1,2};
    vector<int> nums2 = {1,3,4,2};

    vector<int> ans1 = s.nextGreaterElement(nums1, nums2);

    for(int x : ans1)
        cout << x << " ";
    cout << endl;

    // Test 2
    nums1 = {2,4};
    nums2 = {1,2,3,4};

    vector<int> ans2 = s.nextGreaterElement(nums1, nums2);

    for(int x : ans2)
        cout << x << " ";
    cout << endl;

    return 0;
}