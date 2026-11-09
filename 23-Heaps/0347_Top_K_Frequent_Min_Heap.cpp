/*
    Pattern: Hash Map + Min Heap

    Approach:
    - Use an unordered_map to calculate the frequency of each element.
    - Maintain a min heap of size k storing {frequency, element}.
    - Push every unique element into the heap.
    - If heap size exceeds k, remove the least frequent element.
    - The remaining k elements are the top k frequent elements.

    Time Complexity: O(n + m log k)
    Space Complexity: O(m + k)

    Self Note:
    Here m represents the number of distinct elements.

    The min heap keeps the least frequent element at the top.
    Whenever size > k, pop the least frequent element.

    This ensures that the heap always contains the k most
    frequent elements processed so far.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> mp;

        for (int num : nums) {
            mp[num]++;
        }

        vector<int> res;

        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        for (auto it : mp) {

            pq.push({it.second, it.first});

            if (pq.size() > k) {
                pq.pop();
            }
        }

        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
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