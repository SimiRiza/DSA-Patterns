#include <iostream>
#include <vector>
#include<climits>
using namespace std;
int main() {
    // vector<vector<int>> res;
    vector<int> nums = {1, 2, 3, 4, 5,100,7,78,123,3,500};
    int max_ele = INT_MIN,sec = INT_MIN;
    for (int i = 0; i < nums.size(); i++){
        if(nums[i] > max_ele){
            sec = max_ele;
            max_ele = nums[i];
        }
        if(nums[i] > sec && nums[i] < max_ele)
           sec = nums[i];
    }
    cout<<"second max "<<sec;
         return 0;
    }
    
