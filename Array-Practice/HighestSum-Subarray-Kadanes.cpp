#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int main() {
    // vector<vector<int>> res;
    vector<int> nums = {-1, -4 ,1 , 2, 3,-7, 4, 5};
    int max_sum = INT_MIN, curr_sum = 0;
    for (int i = 0; i < nums.size(); i++) {
        if(curr_sum + nums[i] > nums[i]){
            curr_sum += nums[i];
        }
        else
        curr_sum = nums[i];
        max_sum = max(max_sum, curr_sum);
    }
        cout<<"Maximum sum of contiguous subarray: "<<max_sum<<endl;
        return 0;
    }
    
