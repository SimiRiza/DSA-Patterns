#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Approach:
    // Binary search on the smaller array and find a valid partition
    // such that all elements on the left are <= all elements on the right.
    //
    // Time Complexity: O(log(min(n1, n2)))
    // Space Complexity: O(1)

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int n1 = nums1.size(), n2 = nums2.size();

        if(n1 > n2)
            return findMedianSortedArrays(nums2, nums1);

        int n = n1 + n2;
        int start = 0, end = n1;

        while(start <= end){

            int mid = start + (end - start)/2;

            // reset every iteration
            int ryt1 = INT_MAX, ryt2 = INT_MAX;
            int left1 = INT_MIN, left2 = INT_MIN;

            int cut2 = (n + 1)/2 - mid;

            if(mid < n1) ryt1 = nums1[mid];
            if(mid - 1 >= 0) left1 = nums1[mid - 1];

            if(cut2 < n2) ryt2 = nums2[cut2];
            if(cut2 - 1 >= 0) left2 = nums2[cut2 - 1];

            if(left2 > ryt1)
                start = mid + 1;
            else if(left1 > ryt2)
                end = mid - 1;
            else{
                if(n % 2 == 0)
                    return (max(left1, left2) + min(ryt1, ryt2)) / 2.0;

                return max(left1, left2);
            }
        }

        return 0;
    }
};

int main() {

    Solution obj;

    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};

    cout << obj.findMedianSortedArrays(nums1, nums2);

    return 0;
}