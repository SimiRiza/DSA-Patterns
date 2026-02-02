#include <iostream>
#include <vector>
#include <optional>
using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        // optional is used because these values may not exist initially
        // it's supported only in c++17 or newer versions 
        optional<int> firstMax, secondMax, thirdMax;

        // Traverse through each number in the array
        for (int n : nums) {

            // Case 1: n is greater than current firstMax
            // Shift firstMax -> secondMax
            // Shift secondMax -> thirdMax
            if (!firstMax.has_value() || n > firstMax.value()) {
                thirdMax = secondMax;
                secondMax = firstMax;
                firstMax = n;
            }

            // Case 2: n is less than firstMax
            // but greater than secondMax
            else if (n < firstMax.value() &&
                    (!secondMax.has_value() || n > secondMax.value())) {
                thirdMax = secondMax;
                secondMax = n;
            }

            // Case 3: n is less than secondMax
            // but greater than thirdMax
            else if (secondMax.has_value() &&
                     n < secondMax.value() &&
                     (!thirdMax.has_value() || n > thirdMax.value())) {
                thirdMax = n;
            }
        }

        // If third maximum exists, return it
        if (thirdMax.has_value())
            return thirdMax.value();

        // Otherwise, return the maximum value
        return firstMax.value();
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {3, 2, 1};
    cout << sol.thirdMax(nums1) << endl;   // Output: 1

    vector<int> nums2 = {1, 2};
    cout << sol.thirdMax(nums2) << endl;   // Output: 2

    vector<int> nums3 = {2, 2, 3, 1};
    cout << sol.thirdMax(nums3) << endl;   // Output: 1

    return 0;
}
