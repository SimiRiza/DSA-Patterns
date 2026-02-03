#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        int freq[26] = {0};

        // First pass: count frequency of each character
        for (char ch : s)
            freq[ch - 'a']++;

        // Second pass: return first index whose frequency is 1
        for (int i = 0; i < s.size(); i++) {
            if (freq[s[i] - 'a'] == 1)
                return i;
        }

        return -1;
    }
};

int main() {
    Solution sol;
    string s = "loveleetcode";
    cout << sol.firstUniqChar(s) << endl; // Expected output: 2
    return 0;
}
