#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

/*
Approach:
- Use a hash map to count character frequencies.
- Increment for characters in string s.
- Decrement for characters in string t.
- If all counts become zero, the strings are anagrams.

Why this works for Unicode / general characters:
- unordered_map does not assume fixed alphabets.
- Works for any character set supported by char type.

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;

        unordered_map<char, int> freq;

        for (int i = 0; i < s.length(); i++) {
            freq[s[i]]++;
            freq[t[i]]--;
        }

        for (auto &p : freq) {
            if (p.second != 0) return false;
        }

        return true;
    }
};

int main() {
    Solution sol;
    cout << sol.isAnagram("anagram", "nagaram") << endl; // 1
    cout << sol.isAnagram("rat", "car") << endl;         // 0
    return 0;
}
