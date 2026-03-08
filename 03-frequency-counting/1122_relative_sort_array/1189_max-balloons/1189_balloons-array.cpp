/*
Approach: Frequency Array

Instead of a hash map, we use a fixed array of size 26 to store
frequency of lowercase characters.

To construct the word "balloon" we need:
b -> 1
a -> 1
l -> 2
o -> 2
n -> 1

The maximum number of "balloon" words we can build is limited by
the minimum available required characters.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int>freq(26,0);

        for(char ch : text){
            freq[ch-'a']++;
        }

        int cnt = freq['b'-'a'];
        cnt = min(freq['a'-'a'], cnt);
        cnt = min(freq['n'-'a'], cnt);
        cnt = min(freq['l'-'a']/2, cnt);
        cnt = min(freq['o'-'a']/2, cnt);

        return cnt;
    }
};

int main() {
    Solution sol;

    string test1 = "nlaebolko";
    cout << "Test 1 Output: " << sol.maxNumberOfBalloons(test1) << endl; // Expected 1

    string test2 = "loonbalxballpoon";
    cout << "Test 2 Output: " << sol.maxNumberOfBalloons(test2) << endl; // Expected 2

    return 0;
}