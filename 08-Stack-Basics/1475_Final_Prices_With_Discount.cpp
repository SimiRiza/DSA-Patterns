/*
Approach: Monotonic Stack (Next Smaller or Equal Element)
Description:
- Traverse from right to left.
- Maintain a monotonic increasing stack.
- Remove elements greater than current price.
- Top of stack becomes the discount (first next smaller/equal price).

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> res(prices.size());
        stack<int> st;

        // Traverse from right to left
        for(int i = prices.size() - 1; i >= 0; i--) {

            // Remove elements that cannot be discounts
            while(!st.empty() && st.top() > prices[i]) {
                st.pop();
            }

            // If no valid discount exists, keep original price
            if(st.empty())
                res[i] = prices[i];
            else
                res[i] = prices[i] - st.top();

            // Store current price for future elements
            st.push(prices[i]);
        }

        return res;
    }
};

int main() {
    Solution obj;

    // Test 1
    vector<int> prices1 = {8,4,6,2,3};
    vector<int> ans1 = obj.finalPrices(prices1);

    cout << "Test 1: ";
    for(int x : ans1)
        cout << x << " ";
    cout << endl;

    // Test 2
    vector<int> prices2 = {1,2,3,4,5};
    vector<int> ans2 = obj.finalPrices(prices2);

    cout << "Test 2: ";
    for(int x : ans2)
        cout << x << " ";
    cout << endl;

    return 0;
}
