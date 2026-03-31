// Approach: Sliding Window (Circular)
// We maintain a circular window of size k and keep updating sum efficiently.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> decrypt(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> res(n, 0);

        if (k == 0)
            return res;

        if (k < 0) {
            int curr = 0;
            int start = n - abs(k), end = n - 1;
            long long sum = 0;

            // initial window sum
            for (int i = start; i <= end; i++)
                sum += arr[i];

            while (curr < n) {
                res[curr] = sum;

                sum -= arr[start];
                start = (start + 1) % n;

                end = (end + 1) % n;
                sum += arr[end];

                curr++;
            }
        } 
        else {
            int curr = 0;
            int start = 1, end = k;
            long long sum = 0;

            // initial window sum
            for (int i = start; i <= end; i++)
                sum += arr[i % n];

            while (curr < n) {
                res[curr] = sum;

                sum -= arr[start % n];
                start = (start + 1) % n;

                end = (end + 1) % n;
                sum += arr[end];

                curr++;
            }
        }

        return res;
    }
};

int main() {
    Solution obj;

    // Test 1
    vector<int> arr1 = {5, 7, 1, 4};
    int k1 = 3;
    vector<int> res1 = obj.decrypt(arr1, k1);

    cout << "Test 1: ";
    for (int x : res1) cout << x << " ";
    cout << endl;

    // Test 2
    vector<int> arr2 = {2, 4, 9, 3};
    int k2 = -2;
    vector<int> res2 = obj.decrypt(arr2, k2);

    cout << "Test 2: ";
    for (int x : res2) cout << x << " ";
    cout << endl;

    return 0;
}