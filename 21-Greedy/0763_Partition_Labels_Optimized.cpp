/*
    Pattern: Greedy + Last Occurrence

    Approach:
    - First store the last occurrence of every character.
    - While traversing the string, find the last occurrence
      of the current character.
    - Extend the current partition boundary using `farthest`.
    - When the current index reaches `farthest`, the partition
      is complete because every character inside it ends here
      or before here.

    Time Complexity: O(n)
    Space Complexity: O(1)

    Self Note:
    The important idea is to use the LAST occurrence of each
    character, not the first occurrence.

    `farthest` represents the rightmost position that the
    current partition must reach.

    When `i == farthest`, no character inside the partition
    appears outside it, so we can safely cut the partition.
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {

        vector<int> prev_idx(26, -1);

        // Store the last occurrence of every character.
        for (int i = 0; i < s.size(); i++) {
            prev_idx[int(s[i]) - int('a')] = i;
        }

        vector<int> res;
        int farthest = -1;
        int sum = 0;

        for (int i = 0; i < s.size(); i++) {

            int far_idx = prev_idx[int(s[i]) - int('a')];

            if (far_idx > farthest) {
                farthest = far_idx;
            }

            if (i == farthest) {
                res.push_back((i + 1) - sum);
                sum = i + 1;
                farthest = -1;
            }
        }

        return res;
    }
};

int main() {
    Solution solution;

    string s = "ababcbacadefegdehijhklij";

    vector<int> result = solution.partitionLabels(s);

    cout << "Partition sizes: ";

    for (int size : result) {
        cout << size << " ";
    }

    cout << endl;

    return 0;
}