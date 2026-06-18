#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int main() {
    // vector<vector<int>> res;
    vector<int> nums = {-1, -4 ,1 , 2, 3,-7, 4, 5};
    int max_sum = INT_MIN;
    int start = 0, end = 0;
    for (int i = 0; i < nums.size(); i++) {
        int sum = 0;
            for (int j = i; j <= nums.size() - 1; j++) {
                    sum += nums[j];
                    if(sum > max_sum){
                        max_sum = sum;
                        start = i;
                        end = j;
                    }
        }
    }
        cout<<"Maximum sum of contiguous subarray: "<<max_sum<<endl;
        cout<<"Indices: "<<start<<" to "<<end<<endl;
        for(int i = start; i <= end; i++){
            cout<<nums[i]<<" ";
        }
        return 0;
    }
    
