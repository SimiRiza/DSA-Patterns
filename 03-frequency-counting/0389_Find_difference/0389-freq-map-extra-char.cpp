/*
Approach: Frequency Map Difference

Description:
Count frequency of each character in string s using a hashmap.
Then traverse string t and decrement the frequencies.
The character whose frequency becomes non-zero at the end
is the extra character added in t.

Time Complexity: O(n)
Space Complexity: O(1)  (at most 26 lowercase characters)
*/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int> freq_in_s;

        // Count characters from s
        for(auto ch : s){
            freq_in_s[ch]++;
        }

        // Subtract using characters from t
        for(auto ch : t){
            freq_in_s[ch]--;
        }

        // Find the character with non-zero frequency
        for(auto pair : freq_in_s){
            if(pair.second != 0){
                return pair.first;
            }
        }

        return 'a'; // fallback (problem guarantees one extra char)
    }
};

int main() {
    Solution sol;

    // Test case 1
    string s1 = "abcd";
    string t1 = "abcde";
    cout << sol.findTheDifference(s1, t1) << endl;

    // Test case 2
    string s2 = "";
    string t2 = "y";
    cout << sol.findTheDifference(s2, t2) << endl;

    return 0;
}