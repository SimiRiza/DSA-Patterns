/*
    Pattern: Hash Map + Bucket Sort

    Approach:
    - Use an unordered_map to count frequency of every element.
    - Create buckets indexed by frequency.
    - Store elements inside their corresponding frequency buckets.
    - Traverse buckets from highest frequency to lowest.
    - Collect elements until k elements are obtained.

    Time Complexity: O(n) average
    Space Complexity: O(n)

    Self Note:
    Hash Map eliminates the need to sort nums first.
    Bucket traversal avoids sorting elements by frequency.
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        vector<vector<int>> count(nums.size() + 1);
        unordered_map<int, int> mp;

        for (int num : nums) {
            mp[num]++;
        }

        int num = 0;

        for (auto it : mp) {
            count[it.second].push_back(it.first);
        }

        int ans = 0;
        vector<int> res;

        for (int i = count.size() - 1; i >= 0 && ans < k; i--) {

            if (count[i].size() != 0) {
                for (int ele : count[i]) {
                    res.push_back(ele);
                    ans++;
                }
            }
        }

        return res;
    }
};

int main() {
    Solution solution;

    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;

    vector<int> result = solution.topKFrequent(nums, k);

    cout << "Top K frequent elements: ";

    for (int ele : result) {
        cout << ele << " ";
    }

    cout << endl;

    return 0;
}