#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0;i<n;i++){
            for(int j =i+1;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(auto &arr : matrix){
            reverse(arr.begin(),arr.end());
        }
    } 
int main() {
    int n;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n));
    for(int i =0;i<n;i++){
        for(int j =0;j<n;j++){
            cin>>matrix[i][j];
        }
    }
    rotate(matrix);
    for(int i =0;i<n;i++){
        for(int j =0;j<n;j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

}



// int main() {
//     int n;
//     cin >> n;

//     vector<vector<int>> intervals(n, vector<int>(2));
//     vector<vector<int>> res;

//     for (int i = 0; i < n; i++) {
//         cin >> intervals[i][0] >> intervals[i][1];
//     }
//     sort(intervals.begin(),intervals.end());
//     res.push_back(intervals[0]);
//     int res_idx = 0;
//     for(int i =1;i<n;i++){
//         if(intervals[i][0] <= res[res_idx][1]){
//             res[res_idx][1] = max(res[res_idx][1],intervals[i][1]);
//         }

//         else{
//             res.push_back({intervals[i][0], intervals[i][1]});
//             res_idx++;
//         }
//     }
//     for(auto arr : res){
//        cout<<"{"<<arr[0]<<", "<<arr[1]<<endl;
//     }

    

//     return 0;
// }