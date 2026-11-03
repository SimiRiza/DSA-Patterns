/*
    Pattern: Min Heap / Priority Queue

    Approach:
    - Maintain a min heap containing at most k elements.
    - Push every element into the heap.
    - If heap size exceeds k, remove the smallest element.
    - After processing all elements, the heap contains
      the k largest elements.
    - The heap top is the kth largest element.

    Time Complexity: O(n log k)
    Space Complexity: O(k)

    Self Note:
    We use a MIN heap because 
    Whenever size > k:
        pop the smallest element.
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int num : nums) {
            pq.push(num);

            if (pq.size() > k) {
                pq.pop();
            }
        }

        return pq.top();
    }
};

int main() {
    Solution solution;

    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;

    cout << "Kth largest element: "
         << solution.findKthLargest(nums, k) << endl;

    return 0;
}