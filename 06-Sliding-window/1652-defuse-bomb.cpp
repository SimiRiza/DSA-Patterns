// Approach: Circular Sliding Window (Forward + Backward)
// Idea:
// - If k > 0 → sum next k elements (right side)
// - If k < 0 → sum previous k elements (left side)
// - Use circular indexing with modulo
// Time: O(n)
// Space: O(1) extra (excluding result)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> decrypt(vector<int>& arr, int k) {
        vector<int> res(arr.size(), 0);

        if (k == 0) return res;

        if (k > 0) {
            int start = 1, end = 1;
            long long sum = 0;

            while (end <= k) {
                sum += arr[end];
                end++;
            }

            while (start < arr.size()) {
                res[start - 1] = sum;
                sum -= arr[start];
                start++;
                sum += arr[(end) % arr.size()];
                end = (end + 1) % arr.size();
            }

            res[start - 1] = sum;
        }
        else {
            int n = arr.size();
            int start = n - 1, end = n - 1;
            long long sum = 0;

            int cnt = -k;
            while (cnt--) {
                sum += arr[(end - 1 + n) % n];
                end = (end - 1 + n) % n;
            }

            int i = n - 1;
            while (i >= 0) {
                res[i] = sum;

                sum -= arr[(start - 1 + n) % n];
                start = (start - 1 + n) % n;

                sum += arr[(end - 1 + n) % n];
                end = (end - 1 + n) % n;

                i--;
            }
        }

        return res;
    }
};

int main() {
    Solution sol;

    // Test 1
    vector<int> arr1 = {5, 7, 1, 4};
    int k1 = 3;
    vector<int> res1 = sol.decrypt(arr1, k1);
    for (int x : res1) cout << x << " ";
    cout << endl;

    // Test 2
    vector<int> arr2 = {2, 4, 9, 3};
    int k2 = -2;
    vector<int> res2 = sol.decrypt(arr2, k2);
    for (int x : res2) cout << x << " ";
    cout << endl;

    return 0;
}