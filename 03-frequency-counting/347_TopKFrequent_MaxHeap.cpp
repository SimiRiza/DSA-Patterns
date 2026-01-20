// Approach:
// 1. Count frequency of each element using unordered_map
// 2. Use a max-heap (priority_queue) to order elements by frequency
// 3. Extract top k elements from the heap

#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        // Max heap: (frequency, element)
        priority_queue<pair<int, int>> pq;
        for (auto it : freq) {
            pq.push({it.second, it.first});
        }

        vector<int> result;
        while (k-- && !pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }
};
