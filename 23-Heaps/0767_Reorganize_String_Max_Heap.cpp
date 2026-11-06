/*
    Problem: Reorganize String
    LeetCode: 767

    Pattern: Greedy + Max Heap

    Approach:
    - Count the frequency of every character.
    - Store {frequency, character} in a max heap.
    - Always select the most frequent available character.
    - If the heap top is the previous character, temporarily
      hold it and select the next highest-frequency character.
    - Decrease the selected character's frequency and push it
      back if occurrences remain.
    - If no alternative character exists, return "".

    Time Complexity: O(n log 26) = O(n)
    Space Complexity: O(26) = O(1)

    Self Note:
    Never place the same character consecutively.

    The previous character is temporarily excluded from selection.
    After choosing another character, the previous character
    becomes available again if its frequency is still positive.

    If the heap contains no alternative character, reorganization
    is impossible.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

class Solution {
public:
    string reorganizeString(string s) {
        vector<int> mp(26, 0);

        for (char ch : s) {
            mp[ch - 'a']++;
        }

        priority_queue<pair<int, char>, vector<pair<int, char>>> pq;

        for (int i = 0; i < mp.size(); i++) {
            if (mp[i] != 0)
                pq.push({mp[i], char(i + 'a')});
        }

        string str = "";
        char prev_char = 'A';

        while (!pq.empty()) {
            pair<int, char> top_pair = pq.top();

            if (top_pair.second == prev_char) {
                pair<int, char> temp = pq.top();
                pq.pop();

                if (pq.empty())
                    return "";

                top_pair = pq.top();
                pq.pop();

                pq.push(temp);
            }
            else
                pq.pop();

            if (top_pair.first - 1 > 0)
                pq.push({top_pair.first - 1, top_pair.second});

            str += top_pair.second;
            prev_char = top_pair.second;
        }

        return str;
    }
};

int main() {
    Solution solution;

    string s = "aab";

    cout << "Reorganized string: "
         << solution.reorganizeString(s) << endl;

    return 0;
}