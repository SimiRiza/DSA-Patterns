#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;                 // Final answer
        set<vector<int>> duplicate;              // To avoid duplicate triplets

        // Fix the first element
        for(int i = 0; i < nums.size(); i++) {
            int tar = -1 * nums[i];              // Target for remaining two numbers

            // Fix the second element
            for(int j = i + 1; j < nums.size(); j++) {
                int have = nums[j];
                int req = tar - have;            // Required third element

                // Search for the third element
                for(int k = j + 1; k < nums.size(); k++) {
                    if(req == nums[k]) {
                        // Found a valid triplet
                        vector<int> temp = { -tar, have, req };
                        sort(temp.begin(), temp.end());   // Sort for uniqueness

                        // Insert only if not already present
                        if(duplicate.find(temp) == duplicate.end()) {
                            duplicate.insert(temp);
                            res.push_back(temp);
                        }
                    }
                }
            }
        }
        return res;
    }
};
