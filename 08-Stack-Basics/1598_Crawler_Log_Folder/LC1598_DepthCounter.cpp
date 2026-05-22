/*
Approach: Depth Counter / Simulation

Description:
- Keep track of current folder depth using an integer.
- "../" -> move one folder back if depth > 0
- "./"  -> stay in current folder
- "x/"  -> enter a folder, so increase depth

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int minOperations(vector<string>& logs) {
        int depth = 0;

        // Traverse all log operations
        for (string s : logs) {

            // Move back one folder if possible
            if (s == "../" && depth != 0) {
                depth--;
            }

            // Stay in current folder
            else if (s == "./") {
                continue;
            }

            // Enter a new folder
            else if (s != "../") {
                depth++;
            }
        }

        // Final depth = minimum operations to return to main folder
        return depth;
    }
};

int main() {
    Solution obj;

    // Test case 1
    vector<string> test1 = {"d1/","d2/","../","d21/","./"};
    cout << "Output 1: " << obj.minOperations(test1) << endl;

    // Test case 2
    vector<string> test2 = {"d1/","../","../","../"};
    cout << "Output 2: " << obj.minOperations(test2) << endl;

    return 0;
}