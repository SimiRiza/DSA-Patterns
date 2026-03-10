/*
Approach: Greedy Two Pointers (after sorting)

Sort the weights. Use two pointers:
- start -> lightest person
- end   -> heaviest person

If the lightest + heaviest fit in the boat, send both.
Otherwise send the heaviest alone.

Special handling: if someone weighs >= limit they must go alone.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());

        int count = 0;
        int start = 0;
        int end = people.size() - 1;

        // Handle people who must go alone
        while (end >= 0 && people[end] >= limit) {
            count++;
            end--;
        }

        while (start <= end) {
            if (people[start] + people[end] <= limit) {
                count++;
                start++;
                end--;
            }
            else {
                count++;
                end--;
            }
        }

        return count;
    }
};

int main() {
    Solution sol;

    vector<int> test1 = {3, 2, 2, 1};
    cout << sol.numRescueBoats(test1, 3) << endl; // expected 3

    vector<int> test2 = {1, 2};
    cout << sol.numRescueBoats(test2, 3) << endl; // expected 1

    return 0;
}