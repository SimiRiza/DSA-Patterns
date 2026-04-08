// Approach: Last Seen Index Tracking
// Idea: Track last positions of two fruits and adjust window smartly

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& f) {
        int start = 0, end = 0, len = 0, max_len = 1;
        int char1 = f[start], char2;
        int left_most_char1_idx = start, left_most_char2_idx;

        while (end < f.size() && f[end] == f[start]) {
            end++;
        }

        if (end == f.size()) {
            return f.size();
        } else {
            char2 = f[end];
            left_most_char2_idx = end;
        }

        while (end < f.size() && start < f.size()) {
            if (end > 0 && f[end] == char1) {
                if (f[end - 1] != char1) {
                    left_most_char1_idx = end;
                }
            } else if (end > 0 && f[end] == char2) {
                if (f[end - 1] != char2) {
                    left_most_char2_idx = end;
                }
            } else {
                if (f[end - 1] == char1) {
                    start = left_most_char1_idx;
                    char2 = f[end];
                    left_most_char2_idx = end;
                } else if (f[end - 1] == char2) {
                    start = left_most_char2_idx;
                    char1 = f[end];
                    left_most_char1_idx = end;
                }
            }

            len = end - start + 1;
            max_len = max(max_len, len);
            end++;
        }

        return max_len;
    }
};

// Test cases
int main() {
    Solution s;
    vector<int> test1 = {1,2,1};
    vector<int> test2 = {1,2,3,2,2};

    cout << s.totalFruit(test1) << endl; // 3
    cout << s.totalFruit(test2) << endl; // 4

    return 0;
}