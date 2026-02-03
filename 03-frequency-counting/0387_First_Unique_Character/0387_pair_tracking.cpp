#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        // freq_char[i].first  -> frequency of character ('a' + i)
        // freq_char[i].second -> first index where it appeared
        vector<pair<int,int>> freq_char(26, {0, -1});

        int idx = 0;
        for (char ch : s) {
            int pos = ch - 'a';

            // Store index only when character appears for the first time
            if (freq_char[pos].first == 0)
                freq_char[pos].second = idx;

            freq_char[pos].first++;
            idx++;
        }

        // Find minimum index among characters that appeared exactly once
        int min_idx = INT_MAX;
        for (auto ele : freq_char) {
            if (ele.first == 1 && ele.second < min_idx)
                min_idx = ele.second;
        }

        return (min_idx == INT_MAX) ? -1 : min_idx;
    }
};

int main() {
    Solution sol;
    string s = "leetcode";
    cout << sol.firstUniqChar(s) << endl; // Expected output: 0
    return 0;
}
