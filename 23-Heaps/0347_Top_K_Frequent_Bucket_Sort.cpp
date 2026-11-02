/*
    Pattern: Sorting + Frequency Bucket Sort

    Approach:
    - Sort nums so duplicate elements become adjacent.
    - Count the frequency of each distinct element.
    - Store elements inside buckets indexed by frequency.
    - Traverse buckets from highest frequency to lowest.
    - Collect elements until k elements are obtained.

    Time Complexity: O(n log n)
    Space Complexity: O(n)

    Self Note:
    Bucket index represents the frequency of an element.
    count[f] contains all elements appearing exactly f times.

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> count(nums.size() + 1);

        int i = 0, c = 1;

        while (i < nums.size()) {
            c = 1;

            while (i < nums.size() - 1 && nums[i + 1] == nums[i]) {
                c++;
                i++;
            }

            count[c].push_back(nums[i]);
            i++;
        }

        int num = 0;
        vector<int> res;

        for (int i = count.size() - 1; i >= 0 && num < k; i--) {
            if (count[i].size() != 0) {
                for (int ele : count[i]) {
                    res.push_back(ele);
                    num++;
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