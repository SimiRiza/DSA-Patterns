/*
    Pattern: Monotonic Stack + Greedy

    Approach:
    - Maintain a monotonic increasing stack of digits.
    - If the current digit is smaller than the stack top,
      remove the larger digit while we still have removals left.
    - This keeps the resulting number as small as possible.
    - If k is still left after processing all digits,
      remove digits from the end.
    - Remove leading zeros from the final result.

    Time Complexity: O(n)
    Space Complexity: O(n)

    Self Note:
    The key greedy idea is:
    If a larger digit appears before a smaller digit,
    removing that larger digit makes the number smaller.

    If k remains after the scan, the number is already
    monotonic increasing, so remove digits from the end.
*/

#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    string removeKdigits(string nums, int k) {
        stack<int> st;

        st.push(nums[0]);

        for (int i = 1; i < nums.size(); i++) {

            while (!st.empty() && k > 0 && st.top() > nums[i]) {
                st.pop();
                k--;
            }

            st.push(nums[i]);
        }

        string temp = "";

        while (!st.empty()) {
            temp += st.top();
            st.pop();
        }

        while (temp.size() > 0 && temp[temp.size() - 1] == '0') {
            temp.pop_back();
        }

        reverse(temp.begin(), temp.end());

        if (k > 0) {
            while (temp.size() > 0 && k--) {
                temp.pop_back();
            }
        }

        return temp.size() > 0 ? temp : "0";
    }
};

int main() {
    Solution solution;

    string nums = "1432219";
    int k = 3;

    cout << "Smallest number: "
         << solution.removeKdigits(nums, k) << endl;

    return 0;
}