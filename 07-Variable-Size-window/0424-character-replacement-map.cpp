/*
Approach: Variable Size Sliding Window (map)

Idea:
Maintain a window where we can replace at most k characters to make all same.
Track frequency of characters and the max frequency in current window.
If (window size - maxFreq > k), shrink from left.
Keep updating maximum window size.

Time Complexity: O(n)
Space Complexity: O(1)  // at most 26 chars

Self Note ⚠️:
Tried using 'if' instead of 'while' for shrinking — it passed many testcases,
but logically incorrect because window may remain invalid.
Always use 'while' to fully fix the window before updating answer.
*/

#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int start=0,end=0;
        int len=0,max_len=0,max_freq=0;
        unordered_map<char,int> freq;
        
        while(end<s.length()){
            len = end-start+1;
            freq[s[end]]++;
            max_freq=max(max_freq,freq[s[end]]); 

            // shrink window fully until valid
            while(start<s.length() && (len-max_freq)>k){
                freq[s[start]]--;
                start++;
                len = end - start + 1;
            }

            len = end-start+1;
            max_len=max(max_len,len);

            end++;
        }
        return max_len;
    }
};

int main() {
    Solution sol;

    // Test 1
    string s1 = "ABAB";
    int k1 = 2;
    cout << sol.characterReplacement(s1, k1) << endl; // Expected: 4

    // Test 2
    string s2 = "AABABBA";
    int k2 = 1;
    cout << sol.characterReplacement(s2, k2) << endl; // Expected: 4

    return 0;
}