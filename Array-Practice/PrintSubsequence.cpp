#include <iostream>
#include <vector>
using namespace std;
void PrintSeq(vector<int>nums,int i,vector<int> output){
    if(i == nums.size()){
        for(int num : output){
        cout<<num<<" ";
    }
        cout<<endl;
     return;
    }
   
    PrintSeq(nums, i+1, output);
    output.push_back(nums[i]);
    PrintSeq(nums, i+1, output);
}
int main() {
    vector<int> nums = {1, 2};
    PrintSeq(nums, 0, {});
    return 0;
}