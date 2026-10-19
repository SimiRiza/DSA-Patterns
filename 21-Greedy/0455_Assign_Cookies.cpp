/*
    Problem: Assign Cookies
    LeetCode: 455

    Pattern: Greedy + Sorting

    Approach:
    - Sort both children and cookies.
    - Process children from least greedy to most greedy.
    - For each child, skip cookies that are too small.
    - Assign the smallest cookie that can satisfy the child.
    - This preserves larger cookies for children with larger greed.

    Time Complexity: O(n log n + m log m)
    Space Complexity: O(1) auxiliary space
                      (ignoring sorting implementation space)

    Self Note:
    Always try to use the smallest sufficient resource first.
    This greedy choice leaves larger cookies available for greedier children.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int content = 0;
        int i = 0;

        for (int j = 0; j < g.size(); j++) {

            while (i < s.size() && s[i] < g[j]) {
                i++;
            }

            if (i < s.size() && s[i] >= g[j]) {
                content++;
                i++;
            }
        }

        return content;
    }
};

int main() {
    Solution solution;

    vector<int> g = {1, 2, 3};
    vector<int> s = {1, 1};

    cout << "Maximum content children: "
         << solution.findContentChildren(g, s) << endl;

    return 0;
}