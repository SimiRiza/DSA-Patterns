/*
Approach: Binary Search + Shipping Simulation

Idea:
- Binary search on the answer (ship capacity).
- For a given capacity, simulate shipping all packages and count
  how many days are needed.
- If required days <= allowed days, capacity works.
- Otherwise, capacity is too small.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isEnoughCapacity(vector<int>& weights, int m_days, int capacity) {
        int n = weights.size(), curr_sum = 0, days = 0;

        for (int i = 0; i < n; i++) {
            if (weights[i] > capacity)
                return false;

            curr_sum += weights[i];

            // Count the final unfinished ship exactly once.
            if (i == n - 1 && capacity != curr_sum)
                days++;

            if (curr_sum >= capacity) {

                days++;

                if (curr_sum == capacity) {
                    curr_sum = 0;
                } else {
                    // Overflow happened.
                    // Previous valid load is counted as a day.
                    // Current package starts the next day.
                    curr_sum = weights[i];
                }
            }
        }

        return days <= m_days;
    }

    int shipWithinDays(vector<int>& weights, int m_days) {
        int start = 1, total_w = 0;

        for (int w : weights)
            total_w += w;

        int end = total_w;
        int min_capacity = total_w;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (isEnoughCapacity(weights, m_days, mid)) {
                min_capacity = min(min_capacity, mid);
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return min_capacity;
    }
};

int main() {
    Solution sol;

    vector<int> test1 = {1,2,3,4,5,6,7,8,9,10};
    cout << "Test 1: "
         << sol.shipWithinDays(test1, 5)
         << endl;

    vector<int> test2 = {3,3,3,3,3,3};
    cout << "Test 2: "
         << sol.shipWithinDays(test2, 2)
         << endl;

    return 0;
}
/*
SELF NOTE ABOUT:

if(i == n - 1 && capacity != curr_sum)
    days++;

Why is this needed?

My logic counts a day whenever:
1. Ship becomes exactly full (curr_sum == capacity)
2. Ship exceeds capacity (curr_sum > capacity)

But what if I reach the LAST package and the current ship is still
not full?

Example:
weights = [3,3,3,3,3,3]
capacity = 10

Day 1:
3 + 3 + 3 = 9

Day 2:
3 + 3 + 3 = 9

The second ship never reaches capacity 10, so the
(curr_sum >= capacity) condition never counts it.

However, this unfinished ship still exists and must be shipped,
so it represents one final day.

Therefore, when we are at the last package (i == n - 1)
and the ship is NOT exactly full (capacity != curr_sum),
we manually count that remaining unfinished ship.

Important:
If curr_sum == capacity on the last package, the day has already
been counted by the (curr_sum >= capacity) condition, so we must
NOT count it again.

DEBUGGING LESSON:

When a simulation counts "days", always ask:

"Who counts the final unfinished state?"

Many bugs happen because:
- Final state is never counted.
- Final state is counted twice.

The condition:

if(i == n - 1 && capacity != curr_sum)

was added specifically to count the last unfinished ship
exactly once.
*/