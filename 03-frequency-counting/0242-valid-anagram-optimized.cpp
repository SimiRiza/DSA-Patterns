#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/*
Approach:
- Use a fixed-size frequency array of size 26.
- Increment for characters in s.
- Decrement for characters in t.
- If all values are zero, strings are anagrams.

Why this is optimized:
- Constant space (26 letters).
- Faster than hash map.
- Best choice when input is guaranteed to be lowercase English letters.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;

        vector<int> freq(26, 0);

        for (int i = 0; i < s.length(); i++) {
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }

        return all_of(freq.begin(), freq.end(),
                      [](int x) { return x == 0; });
    }
};

int main() {
    Solution sol;
    cout << sol.isAnagram("listen", "silent") << endl; // 1
    cout << sol.isAnagram("hello", "bello") << endl;   // 0
    return 0;
}
