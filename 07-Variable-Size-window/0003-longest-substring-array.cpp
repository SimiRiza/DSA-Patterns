// Approach: Sliding Window with Frequency Array
// We maintain a window [start, end) and track characters using a fixed array.
// If duplicate found, shrink window until it's valid again.

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> duplicates(256,0); // freq array for ASCII chars

        if(s.length()==0 )return 0;

        int start = 0, end = 0, curr_len = 1, max_len = 1;

        // sliding window
        while (start < s.length() && end < s.length()) {

            // if current char already exists in window → duplicate
            if(duplicates[int(s[end])] == 1){

                // shrink window until duplicate char is removed
                while((s[start]) != s[end] && start < s.length()) {
                    duplicates[int(s[start])] = 0; // remove char from window
                    start++;
                }

                start++; // skip the previous occurrence of duplicate
            }

            duplicates[int(s[end])] = 1; // add current char to window
            end++;

            curr_len = end - start; // current valid window length
            max_len = max(max_len, curr_len); // update max
        }

        // final check (edge case)
        curr_len = end - start;
        max_len = max(max_len, curr_len);

        return max_len;
    }
};

int main() {
    Solution sol;

    // Test Case 1: normal case
    string s1 = "abcabcbb";
    cout << "Input: " << s1 << " -> Output: " << sol.lengthOfLongestSubstring(s1) << endl;

    // Test Case 2: all same characters
    string s2 = "bbbbb";
    cout << "Input: " << s2 << " -> Output: " << sol.lengthOfLongestSubstring(s2) << endl;

    return 0;
}