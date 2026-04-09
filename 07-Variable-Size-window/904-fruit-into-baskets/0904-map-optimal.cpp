// Approach: Sliding Window (Optimal)
// Idea: Expand window, shrink when >2 types, track max length

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& f) {
        int start = 0;
        unordered_map<int,int> fruits; // stores count of each fruit in window
        int max_len = 0;

        for(int end = 0; end < f.size(); end++) {
            fruits[f[end]]++; // include current fruit

            // shrink window until only 2 types remain
            while(fruits.size() > 2) {
                fruits[f[start]]--; 
                if(fruits[f[start]] == 0)
                    fruits.erase(f[start]); // remove type completely
                start++; // move window start
            }

            // update max valid window size
            max_len = max(max_len, end - start + 1);
        }
        return max_len;
    }
};

int main() {
    Solution sol;

    vector<int> f1 = {1,2,3,2,2};
    cout << "Output 1: " << sol.totalFruit(f1) << endl; // 4

    vector<int> f2 = {1,2,1,2,3};
    cout << "Output 2: " << sol.totalFruit(f2) << endl; // 4

    return 0;
}