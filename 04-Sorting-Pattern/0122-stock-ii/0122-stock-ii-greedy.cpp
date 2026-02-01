#include <iostream>
#include <vector>
using namespace std;

/*
 * LeetCode 122 - Best Time to Buy and Sell Stock II
 * Approach: Greedy (sum all upward price differences)
 * Time: O(n)
 * Space: O(1)
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;

        for (int i = 0; i < prices.size() - 1; i++) {
            if (prices[i + 1] > prices[i]) {
                profit += prices[i + 1] - prices[i];
            }
        }

        return profit;
    }
};

int main() {
    Solution s;
    vector<int> prices = {7, 1, 5, 6, 3, 4};
    cout << s.maxProfit(prices) << endl;
    return 0;
}
