/*
Approach: Frequency Map + Ordered Rebuild

Description:
First count frequencies of all elements in arr1 using a hashmap.
Then place elements that appear in arr2 into arr1 in the exact order of arr2
based on their frequencies. Those elements are removed from the map.

After that, the remaining elements (not present in arr2) are written back
using their stored frequencies. Finally, that leftover portion is sorted
to satisfy the problem requirement.

Time Complexity:
O(n + k log k)
n = size of arr1
k = number of elements not present in arr2 (sorted portion)

Space Complexity:
O(n) for frequency hashmap
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {

        unordered_map<int,int> count_ele;

        // Count frequencies of arr1 elements
        for(int ele : arr1){
            count_ele[ele]++;
        }

        int ele_ptr = 0, cur = 0;

        // Place elements according to arr2 order
        while(ele_ptr < arr2.size()){
            int ele = arr2[ele_ptr];
            int start = cur;
            int count = count_ele[ele];

            while(start <= cur + count - 1){
                arr1[start] = ele;
                start++;
            }

            count_ele.erase(ele); // remove processed element
            cur = start;
            ele_ptr++;
        }

        int last = cur;

        // Place remaining elements (not in arr2)
        for(auto rem_ele : count_ele){
            int val = rem_ele.first;
            int freq = rem_ele.second;

            while(freq--){
                arr1[cur] = val;
                cur++;
            }
        }

        // Sort leftover elements
        sort(arr1.begin() + last, arr1.end());

        return arr1;
    }
};

int main(){

    Solution sol;

    vector<int> arr1 = {2,3,1,3,2,4,6,7,9,2,19};
    vector<int> arr2 = {2,1,4,3,9,6};

    vector<int> res1 = sol.relativeSortArray(arr1, arr2);

    for(int x : res1) cout << x << " ";
    cout << endl;

    vector<int> arr3 = {2,21,43,38,0,42,33,7,24,13,12,27,12,24,5,23,29,48,30,31};
    vector<int> arr4 = {2,42,38,0,43,21};

    vector<int> res2 = sol.relativeSortArray(arr3, arr4);

    for(int x : res2) cout << x << " ";
    cout << endl;

    return 0;
}