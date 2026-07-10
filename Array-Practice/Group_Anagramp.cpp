#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;
int main(){
    int n;
    cin>>n;
      vector<string> strs(n);
    for(int i =0;i<n;i++){
        cin>>strs[i];
    }
    unordered_map<string,vector<string>> res_map;
    for(string s: strs){
        string key = s;
        sort(key.begin(),key.end());
        res_map[key].push_back(s);
    }
    vector<vector<string>> res;
    for(auto map_obj : res_map){
        res.push_back(map_obj.second);
    }
    cout<<"[";
    for(auto res_obj : res){
        cout<<"[";
        for(int i =0;i<res_obj.size();i++){
            cout<<res_obj[i];
            if(i != res_obj.size()-1)
                cout<<",";
        }
        cout<<"]";
    }
    cout<<"]";

}