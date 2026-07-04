#include <iostream>
#include <vector>
#include <algorithm>
#include<climits>
using namespace std;

int main() {
    vector<int> v = {5,-1,2,-3,8};
    int curr_sum = v[0];
    int max_sum = v[0];
    for(int num : v){
        curr_sum += num;
        curr_sum = max(curr_sum,num);
        max_sum = max(max_sum,curr_sum);
    }
    cout<<max_sum;
    return 0;
}


// int main() {
//     vector<int> v = {5,-1,2,-3,8};
//     int curr_sum = v[0];
//     int max_sum = v[0];
//     for(int num : v){
//         curr_sum += num;
//         curr_sum = max(curr_sum,num);
//         max_sum = max(max_sum,curr_sum);
//     }
//     cout<<max_sum;
//     return 0;
// }


// int main() {

//     vector<int> v = {5,0,2,0,8};
//     int k = 3;//kth maximum element
//     sort(v.begin(),v.end());
//     cout<<"Largest kth element "<<v[v.size()-k];
//     cout<<"Smallest kth element "<<v[k-1];
//     return 0;
// }

// int main() {

//     vector<int> nums = {5,0,2,0,8};
//     vector<int> res(nums.size());
//     int k = 3;
//     k %= nums.size();
//     for(int i =0;i<nums.size();i++){
//         res[(i+k) % nums.size()] = nums[i];
//     }
    
//     for(int num : res)
//     cout<<num<<" ";
    
//          return 0;
// }

//     vector<int> nums = {5,0,2,0,8};
//     int idx = 0;
//     int ptr = 0;
//     for(int ptr = 0;ptr<nums.size();ptr++){
//         if(nums[ptr] != 0){
//             nums[idx] = nums[ptr];
//             idx++;
//         }
//     }
//     while(idx < nums.size()){
//         nums[idx] = 0;
//         idx++;
//     }

//     for(int num : nums)
//     cout<<num<<" ";
    
//          return 0;
// }
// int main() {

//     vector<int> nums = {1, 2,3,3, 3, 4, 5,5,5,5,7,8,8,10,10};
//     vector<int> res;
//     int prev = -1;
//     for(int num : nums){
//     if(num != prev){
//         res.push_back(num);
//         prev = num;
//     }
// }
//     for(int num : res)
//     cout<<num<<" ";
    
//          return 0;
//     }


// Better to use:
// for (int i = 0; i < nums.size(); i++) {
//     if (i == 0 || nums[i] != nums[i - 1])
//         res.push_back(nums[i]);
// }
