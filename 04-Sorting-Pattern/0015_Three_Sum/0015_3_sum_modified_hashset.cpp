/*
    Approach: Brute Force + HashSet + Set (to avoid duplicates)

    Idea:
    - Fix first element using index i
    - For remaining elements, use a hashset to check if
      -(nums[i] + nums[j]) already appeared
    - Store triplets in a set to avoid duplicates

    Time Complexity: O(n^2 log k)
        - Two nested loops -> O(n^2)
        - Insertion into set -> O(log k)

    Space Complexity: O(n)
        - HashSet + Set storage
*/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        // Set to automatically remove duplicate triplets
        set<vector<int>> uniqueTriplets;

        for(int i = 0; i < n; i++) {

            // HashSet for checking complement
            set<int> hashset;

            for(int j = i + 1; j < n; j++) {

                int third = -(nums[i] + nums[j]);

                // If complement already seen, we found a triplet
                if(hashset.find(third) != hashset.end()) {

                    vector<int> temp = {nums[i], nums[j], third};

                    // Sort to maintain consistent ordering
                    sort(temp.begin(), temp.end());

                    uniqueTriplets.insert(temp);
                }

                // Insert current number into hashset
                hashset.insert(nums[j]);
            }
        }

        // Convert set to vector
        return vector<vector<int>>(uniqueTriplets.begin(), uniqueTriplets.end());
    }
};


// -----------------------
// Driver Code for Testing
// -----------------------
int main() {

    Solution sol;

    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    vector<vector<int>> result = sol.threeSum(nums);

    cout << "Triplets summing to zero:\n";

    for(const auto& triplet : result) {
        for(int num : triplet) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
