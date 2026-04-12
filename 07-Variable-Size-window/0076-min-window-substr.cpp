#include <iostream>
#include <unordered_map>
#include <climits>
using namespace std;

/*
Approach: Sliding Window + Frequency Map

Idea:
Expand window using 'end' → match characters
When all chars matched → shrink from 'start'
Track minimum valid window

Time: O(n)
Space: O(1) (since char set is limited)

Self Notes :
- Update answer ONLY when window is valid (count == t.size())
- Always do need[s[end]]-- (outside if)
- Never store substring repeatedly → causes MLE
- Store start index + length instead
*/

class Solution {
public:
    string minWindow(string s, string t) {
        int start = 0, end = 0;
        int min_len = INT_MAX, start_idx = 0;
        int count = 0;

        unordered_map<char,int> need;

        // build frequency map
        for(char c : t) {
            need[c]++;
        }

        while(end < s.length()) {

            // expand window
            if(need[s[end]] > 0) {
                count++; // matched useful char
            }
            need[s[end]]--; // ALWAYS decrement (even if not needed)

            // shrink window when valid
            while(count == t.size()) {

                // update answer BEFORE shrinking
                if((end - start + 1) < min_len) {
                    min_len = end - start + 1;
                    start_idx = start;
                }

                // remove start char
                need[s[start]]++;

                // if it becomes needed again → we lost a valid char
                if(need[s[start]] > 0) {
                    count--;
                }

                start++;
            }

            end++;
        }

        // build result once (avoid memory issues)
        return min_len == INT_MAX ? "" : s.substr(start_idx, min_len);
    }
};

// test
int main() {
    Solution obj;

    cout << obj.minWindow("ADOBECODEBANC", "ABC") << endl; // BANC
    cout << obj.minWindow("a", "a") << endl;               // a

    return 0;
}