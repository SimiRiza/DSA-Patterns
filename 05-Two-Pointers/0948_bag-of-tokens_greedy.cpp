/*
Approach: Greedy Two-Pointer

Idea:
- Sort tokens.
- Use two pointers:
    face_up  -> smallest token (gain score)
    face_down -> largest token (gain power)
- If we have enough power, play the smallest token face up (score++).
- Otherwise if we have score, play largest token face down (power++).
- Continue until pointers meet.

Time Complexity: O(n log n)  (sorting)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());

        int face_up = 0, face_down = tokens.size() - 1;
        int score = 0;

        while (face_up < face_down) {
            if (power >= tokens[face_up]) {
                score++;
                power -= tokens[face_up];
                face_up++;
            }
            else if (score >= 1) {
                score--;
                power += tokens[face_down];
                face_down--;
            }
            else {
                return 0;
            }
        }

        if (face_up == face_down) {
            if (power >= tokens[face_up])
                score++;
        }

        return score;
    }
};

int main() {
    Solution sol;

    vector<int> t1 = {100};
    cout << "Test 1 Output: " << sol.bagOfTokensScore(t1, 50) << endl;

    vector<int> t2 = {100, 200, 300, 400};
    cout << "Test 2 Output: " << sol.bagOfTokensScore(t2, 200) << endl;

    return 0;
}