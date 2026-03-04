/*
Approach: Two-Pointer Partition + Frequency Rebuild

Description:
First partition arr1 so that all elements present in arr2 stay on the left side
and elements not present in arr2 move to the right using a two-pointer technique.
Then sort the leftover elements (those not in arr2).
Finally rebuild the left portion using frequency counts in the order defined by arr2.

Time Complexity:
O(n + k log k)
n = size of arr1
k = number of leftover elements not present in arr2

Space Complexity:
O(n) for frequency map
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {

        unordered_map<int,int> mp;

        for(int i = 0; i < arr2.size(); i++){
            mp[arr2[i]] = i;   // store elements of arr2 for quick lookup
        }

        int curr = 0;
        int last = arr1.size() - 1;

        // Note to myself:
        // When curr == last, either curr++ (valid element) or last-- (invalid element) happens.
        // In both cases pointers cross naturally, and final last++ correctly marks the boundary.
        // So no special handling for curr == last is needed.

        while(curr <= last){
            if(mp.count(arr1[curr])){
                curr++; // element belongs to arr2 region
            }
            else{
                swap(arr1[curr], arr1[last]); // push element to leftover region
                last--;
            }
        }

        last++; // start index of leftover region

        // sort elements not present in arr2
        sort(arr1.begin() + last, arr1.end());

        unordered_map<int,int> count_ele;

        // count frequency of elements belonging to arr2
        for(int i=0;i<last;i++){
            count_ele[arr1[i]]++;
        }

        int ele_ptr = 0,cur=0;

        // rebuild left portion in arr2 order
        while(ele_ptr < arr2.size() && cur<last){
            int ele = arr2[ele_ptr];
            int start=cur;
            int count = count_ele[arr2[ele_ptr]];

            while(start<=cur+count-1){
                arr1[start] = ele;
                start++;
            }

            cur=start;
            ele_ptr++;
        }

        return arr1;
    }
};

int main(){

    Solution sol;

    vector<int> arr1 = {2,3,1,3,2,4,6,7,9,2,19};
    vector<int> arr2 = {2,1,4,3,9,6};

    vector<int> result = sol.relativeSortArray(arr1, arr2);

    for(int x : result) cout << x << " ";
    cout << endl;

    vector<int> arr3 = {28,6,22,8,44,17};
    vector<int> arr4 = {22,28,8,6};

    vector<int> result2 = sol.relativeSortArray(arr3, arr4);

    for(int x : result2) cout << x << " ";
    cout << endl;

    return 0;
}