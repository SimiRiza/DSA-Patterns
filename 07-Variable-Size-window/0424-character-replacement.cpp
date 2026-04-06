// Approach: Variable Size Sliding Window
// Idea:
// Maintain a window where we can replace at most k characters to make all same.
// Track frequency of characters and the max frequency in current window.
// If (window size - maxFreq > k), shrink from left.
// Keep updating maximum window size.

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int freq[26] = {0};
        
        int left = 0, maxFreq = 0, ans = 0;
        
        for (int right = 0; right < s.size(); right++) {
            freq[s[right] - 'A']++;
            
            maxFreq = max(maxFreq, freq[s[right] - 'A']);
            
            // shrink window if invalid
            while ((right - left + 1) - maxFreq > k) {
                freq[s[left] - 'A']--;
                left++;
            }
            
            ans = max(ans, right - left + 1);
        }
        
        return ans;
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