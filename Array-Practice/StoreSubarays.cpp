#include <iostream>
#include <vector>
using namespace std;
int main() {
    // vector<vector<int>> res;
    vector<int> nums = {1, 2, 3, 4, 5};
    for (int i = 0; i < nums.size(); i++) {
        vector<int> temp;
            for (int start = i; start <= nums.size() - 1; start++) {
                temp.push_back(nums[start]);
                 for(int num : temp){
                    cout<<num<<" ";
            }
            cout<<endl;
           
        }
         // Print res
    // for (int i = 0; i < res.size(); i++) {
    //     for (int j = 0; j < res[i].size(); j++) {
    //         cout << res[i][j] << " ";
    //     }
    //     cout << endl;
    }
        return 0;
    }
    
