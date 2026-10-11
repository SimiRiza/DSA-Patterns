#include <bits/stdc++.h>
using namespace std;

/*
Problem: LeetCode 134 - Gas Station
Pattern: Greedy — Reset Starting Point

Approach:
- Calculate total gas and total cost.
- Track currentGas while traversing the stations.
- If currentGas becomes negative, the current starting station
  cannot reach the next station.
- Reset currentGas and choose the next station as the start.
- If total gas >= total cost, a solution exists.

Time: O(n)
Space: O(1)

Self Note:
- If totalGas < totalCost, completing the circuit is impossible.
- If currentGas becomes negative at station i, no station
  between the current start and i can be a valid starting point.
- Therefore, restart from i + 1.

Intuition:
A failed journey eliminates every station in that journey
as a possible starting point. One pass is enough.
*/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0;
        int totalCost = 0;
        int currentGas = 0;
        int startingStation = 0;

        for(int i = 0; i < gas.size(); i++) {
            totalGas += gas[i];
            totalCost += cost[i];

            currentGas += gas[i] - cost[i];

            if(currentGas < 0) {
                startingStation = i + 1;
                currentGas = 0;
            }
        }

        return totalGas >= totalCost ? startingStation : -1;
    }
};

int main() {
    Solution sol;

    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};

    cout << sol.canCompleteCircuit(gas, cost) << endl;

    return 0;
}