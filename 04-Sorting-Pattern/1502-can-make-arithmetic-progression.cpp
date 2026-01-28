#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        // Sort the array so elements are in increasing order
        sort(arr.begin(), arr.end());

        // Calculate the expected common difference using
        // (last element - first element) / (number of gaps)
        int d = (arr.back() - arr.front()) / (arr.size() - 1);

        // Check if every consecutive pair has the same difference
        for (int i = 1; i < arr.size(); i++) {
            int diff = arr[i] - arr[i - 1];

            // If any difference does not match the expected one,
            // it cannot form an arithmetic progression
            if (diff != d) {
                return false;
            }
        }

        // All consecutive differences matched
        return true;
    }
};
