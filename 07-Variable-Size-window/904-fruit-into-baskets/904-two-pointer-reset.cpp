// Approach: Two Pointer Reset
// Idea: Expand window, when 3rd type appears reset start to last block

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& f) {
        int start = 0, end = 0, len = 0, max_len = 1;
        int char1 = f[start], char2;

        while (end < f.size() && f[end] == f[start]) {
            end++;
        }

        if (end == f.size()) {
            return f.size();
        } else {
            char2 = f[end];
        }

        while (end < f.size() && start < f.size()) {
            if (f[end] != char1 && f[end] != char2) {
                char2 = f[end];
                start = end - 1;
                char1 = f[start];
            }

            while (start > 0 && f[start - 1] == f[start]) {
                start--;
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
    vector<int> test2 = {0,1,2,2};

    cout << s.totalFruit(test1) << endl; // 3
    cout << s.totalFruit(test2) << endl; // 3

    return 0;
}