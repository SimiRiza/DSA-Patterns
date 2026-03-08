/*
Approach: Two Pointers (In-place Reverse)

We keep two pointers:
- st at the beginning
- e at the end

Swap characters and move both pointers toward the center.
This reverses the vector without extra space.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int st = 0, e = s.size() - 1;

        // swap from both ends until pointers cross
        while (st <= e) {
            swap(s[st], s[e]);
            st++;
            e--;
        }
    }
};

int main() {
    Solution sol;

    vector<char> test1 = {'h','e','l','l','o'};
    sol.reverseString(test1);
    for(char c : test1) cout << c << " ";
    cout << endl;

    vector<char> test2 = {'H','a','n','n','a','h'};
    sol.reverseString(test2);
    for(char c : test2) cout << c << " ";
    cout << endl;

    return 0;
}