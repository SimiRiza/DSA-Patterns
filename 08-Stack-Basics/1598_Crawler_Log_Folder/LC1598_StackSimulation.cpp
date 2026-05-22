/*
Approach: Stack Simulation

Description:
- Simulate folder navigation using a stack.
- Folder name ("x/")  -> push into stack
- "../" -> move back, so pop if stack is not empty
- "./"  -> stay in current folder, do nothing

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> st;

        // Process every operation in logs
        for (string s : logs) {

            // Move back one folder if possible
            if (!st.empty() && s == "../") {
                st.pop();
            }

            // Stay in same folder
            else if (s == "./") {
                continue;
            }

            // Enter a new folder
            else if (s != "../") {
                st.push(s);
            }
        }

        // Remaining stack size = current folder depth
        return st.size();
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