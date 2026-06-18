#include <iostream>
#include <vector>
using namespace std;
 void  PrintSeq(vector<int>& nums,int i,vector<int> output, vector<vector<int>>& arr){
    if(i == nums.size()){
    arr.push_back(output);
    return;
    }
   
     PrintSeq(nums, i+1, output, arr);
    output.push_back(nums[i]);
     PrintSeq(nums, i+1, output, arr);
}
int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> arr;
    vector<int> output ={};
    PrintSeq(nums, 0, output, arr);
    for(vector<int> subseq : arr){
        for(int n : subseq){
            cout<<n<<" ";
        }
        cout<<endl;
    }
    return 0;
}