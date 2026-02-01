#include <iostream>
#include <vector>
using namespace std;

/*
 * LC 122 - Best Time to Buy and Sell Stock II
 * Approach: State-based buy/sell simulation
 * Time: O(n)
 * Space: O(1)
 */

class Solution {
public:
    int maxProfit(vector<int>& a) {
        int current_profit = 0, overall_profit = 0;
        int stock_bought = -1;
        int n = a.size();

        for (int i = 0; i < n - 1; ) {
            if (stock_bought == -1) {
                // Buy if next day's price is higher
                if (a[i + 1] > a[i]) {
                    stock_bought = a[i];
                }
                i++;
            } else {
                // Sell when profitable
                if (a[i] > stock_bought) {
                    current_profit = a[i] - stock_bought;
                    overall_profit += current_profit;
                    stock_bought = -1;
                }
            }
        }

        // Handle possible sell on last day
        if (stock_bought != -1 && a[n - 1] > stock_bought) {
            overall_profit += (a[n - 1] - stock_bought);
        }

        return overall_profit;
    }
};

int main() {
    Solution s;
    vector<int> a = {7, 1, 5, 6, 3, 4};
    cout << s.maxProfit(a) << endl;
    return 0;
}
