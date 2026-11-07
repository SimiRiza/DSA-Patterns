/*
    Pattern: Greedy + Max Heap + Simulation

    Approach:
    - Count the frequency of every task.
    - Store task frequencies in a max heap.
    - Execute tasks in cycles of length n + 1.
    - In each cycle, select up to n + 1 tasks with highest frequencies.
    - Decrease their frequencies and push remaining occurrences back.
    - If tasks remain, the cycle consumes n + 1 time units.
    - If no tasks remain, count only the tasks actually executed.

    Time Complexity: O(T log 26) = O(T)
    Space Complexity: O(26) = O(1)

    Self Note:
    A cycle of length n + 1 ensures that the same task
    cannot execute again before its cooldown finishes.

    The final cycle may be incomplete, so count only the
    tasks executed in that cycle instead of n + 1.

    T = total number of tasks.
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> mp(26, 0);

        for (char ch : tasks) {
            mp[ch - 'A']++;
        }

        priority_queue<int> pq;

        for (int freq : mp) {
            if (freq != 0)
                pq.push(freq);
        }

        int count = 0;

        while (!pq.empty()) {
            vector<int> temp = {};
            int cycle = n + 1;

            while (!pq.empty() && cycle--) {
                temp.push_back(pq.top());
                pq.pop();
            }

            for (int f : temp) {
                if (f - 1 != 0)
                    pq.push(f - 1);
            }

            if (pq.empty())
                count += temp.size();
            else
                count += (n + 1);
        }

        return count;
    }
};

int main() {
    Solution solution;

    vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
    int n = 2;

    cout << "Minimum intervals: "
         << solution.leastInterval(tasks, n) << endl;

    return 0;
}