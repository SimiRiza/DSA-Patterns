#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

/*
Approach:
- For each string, build a frequency signature of 26 lowercase letters
- Convert that frequency array into a unique string key
- Use the key to group anagrams using a hash map

Time Complexity: O(n * k)
Space Complexity: O(n)
where:
n = number of strings
k = average length of each string
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (string s : strs) {
            vector<int> freq(26, 0);

            // count characters
            for (char c : s) {
                freq[c - 'a']++;
            }

            // build unique key from frequency
            string key;
            for (int count : freq) {
                key += to_string(count) + '#';
            }

            mp[key].push_back(s);
        }

        vector<vector<string>> result;
        for (auto& it : mp) {
            result.push_back(it.second);
        }

        return result;
    }
};

// Runnable main for local testing
int main() {
    Solution sol;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

    vector<vector<string>> res = sol.groupAnagrams(strs);

    for (auto& group : res) {
        for (auto& word : group) {
            cout << word << " ";
        }
        cout << endl;
    }

    return 0;
}
