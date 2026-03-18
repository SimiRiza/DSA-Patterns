/*
Approach: Group Frequency Comparison (Two Pointer)

Idea:
- Traverse both strings using two pointers.
- For each group of same characters in `name`, count frequency.
- Match same character group in `typed`:
    -> must have >= frequency
- If any mismatch → false

Time Complexity: O(n + m)
Space Complexity: O(1)
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int name_ptr = 0, typed_ptr = 0;

        while (name_ptr < name.size() && typed_ptr < typed.size()) {
            char tofind = name[name_ptr];
            int freq_find = 1;

            // count group in name
            while (name_ptr + 1 < name.size() && name[name_ptr + 1] == tofind) {
                name_ptr++;
                freq_find++;
            }

            // match required freq in typed
            while (freq_find) {
                if (typed_ptr >= typed.size() || typed[typed_ptr] != tofind)
                    return false;
                typed_ptr++;
                freq_find--;
            }

            // skip extra long presses in typed
            while (typed_ptr < typed.size() && typed[typed_ptr] == tofind) {
                typed_ptr++;
            }

            name_ptr++;
        }

        return name_ptr == name.size() && typed_ptr == typed.size();
    }
};

// ---- Driver Code ----
int main() {
    Solution sol;

    // Test 1
    string name1 = "alex", typed1 = "aaleex";
    cout << (sol.isLongPressedName(name1, typed1) ? "true" : "false") << endl;

    // Test 2
    string name2 = "leelee", typed2 = "lleeelee";
    cout << (sol.isLongPressedName(name2, typed2) ? "true" : "false") << endl;

    return 0;
}