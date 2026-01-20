// Optimized Approach:
// 1. Count frequency using unordered_map
// 2. Use a min-heap of size k
// 3. Remove the smallest frequency whenever heap size exceeds k
// Time Complexity: O(n log k)

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

        // Min heap: keeps only top k frequent elements
        priority_queue<pair<int,int>,
                       vector<pair<int,int>>,
                       greater<pair<int,int>>> pq;

        for (auto it : freq) {
            pq.push({it.second, it.first});
            if (pq.size() > k) {
                pq.pop(); // remove smallest frequency
            }
        }

        vector<int> result;
        while (!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }
};
