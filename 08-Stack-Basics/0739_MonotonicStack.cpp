/*
Approach: Monotonic Decreasing Stack
Description:
- Traverse temperatures from right to left.
- Store indices in stack instead of temperature values.
- Remove all temperatures that are smaller than or equal to current temperature.
- If stack is not empty, the top index gives the next warmer day.
- Distance = next warmer day index - current index.
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        vector<int> res(temp.size(), 0);
        stack<int> st; // Stores indices

        // Traverse from right to left
        for (int i = temp.size() - 1; i >= 0; i--) {

            // Remove temperatures that cannot be next warmer days
            while (!st.empty() && temp[st.top()] <= temp[i]) {
                st.pop();
            }

            // If stack still has an element, top is next warmer day
            if (!st.empty()) {
                res[i] = st.top() - i;
            }

            // Store current index
            st.push(i);
        }

        return res;
    }
};

int main() {
    Solution sol;

    // Test case 1
    vector<int> temp1 = {73,74,75,71,69,72,76,73};
    vector<int> ans1 = sol.dailyTemperatures(temp1);

    cout << "Test 1: ";
    for (int x : ans1) cout << x << " ";
    cout << endl;

    // Test case 2
    vector<int> temp2 = {30,40,50,60};
    vector<int> ans2 = sol.dailyTemperatures(temp2);

    cout << "Test 2: ";
    for (int x : ans2) cout << x << " ";
    cout << endl;

    return 0;
}