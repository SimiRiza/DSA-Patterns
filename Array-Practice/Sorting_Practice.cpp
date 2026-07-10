#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;
void BubbleSort(int *arr, int n){
    for(int i =0;i<n-1;i++){
        for(int j =0;j<n-i-1;j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}
void SelectionSort(int *arr, int n){
    for(int i =0;i<n-1;i++){
        int mini = i;
        for(int j =i+1;j<n;j++){
            if(arr[j] < arr[mini]){
               mini = j;
            }
        }
         swap(arr[i],arr[mini]);
    }
}
void InsertinSort(int *arr, int n){
    for(int i =1;i<n;i++){
        int j = i;
        while(j>0 && arr[j]<arr[j-1]){
                swap(arr[j],arr[j-1]);
                j--;
        }
    }
}
void merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp;

    int left = low;
    int right = mid + 1;

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        } else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

void mergeSort(vector<int> &arr, int low, int high) {
    if (low >= high)
        return;

    int mid = low + (high - low) / 2;

    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);

    merge(arr, low, mid, high);
}
int main(){
    int n;
    cin>>n;
    // int arr[n];
    vector<int> arr(n);
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
    // BubbleSort(arr, n);
    // SelectionSort(arr, n);
    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

// int main(){
//     int big =6,small =50,temp;
//     while(small != 0){
//         temp = big;
//         big = small;
//         small = temp % small;
//     }
//     cout<<small;
// }

// int main(){
//     int a =6,b=50,temp;
//     int big = max(a,b),small = min(a,b);
//     while(small != 0){
//         if(big % small == 0){
//             cout<<small;
//             break;
//         }
//         temp = big;
//         big = small;
//         small = temp % small;
//     }
// }