/*
    Pattern: Greedy + Last Occurrence / Boundary Tracking

    Approach:
    - Track the last occurrence of every character.
    - While scanning the string, keep extending the current
      partition boundary whenever a character appears later.
    - A partition can end only when the current index reaches
      the farthest required occurrence.
    - Store the size of each valid partition.

    Time Complexity: O(n)
    Space Complexity: O(n)

    Self Note:
    A partition is valid only when every character inside it
    has all of its occurrences inside the same partition.

    The key greedy idea:
    Keep extending the partition until no character inside
    the current partition appears beyond its boundary.
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> next_occ(s.size(), 0);
        vector<int> prev_idx(26, -1);

        for (int i = 0; i < s.size(); i++) {

            int prev_indx = prev_idx[int(s[i]) - int('a')];

            if (prev_indx != -1) {
                next_occ[prev_indx] = i;
            }

            prev_idx[int(s[i]) - int('a')] = i;
        }

        vector<int> res;
        int farthest = -1;
        int sum = 0;

        for (int i = 0; i < next_occ.size(); i++) {

            if (next_occ[i] > farthest) {
                farthest = next_occ[i];
            }

            if ((i == farthest || farthest == 0) && next_occ[i] == 0) {
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