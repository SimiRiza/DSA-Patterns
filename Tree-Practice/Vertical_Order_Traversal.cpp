#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

void updateMap_verticalOrder(Node* root,int x,map<int,vector<int>> &mp){
    if(root){
        if(mp.count(x)!=0){
            mp[x].push_back(root->data);
        }
        else{
            mp[x] = {root->data};
        }
    }
    else{
        return;
    }
    updateMap_verticalOrder(root->left,x-1,mp);
    updateMap_verticalOrder(root->right,x+1,mp);

    }


int main(){

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    map<int,vector<int>> mp;
    int x = 0;
    updateMap_verticalOrder(root,x,mp);

    for(auto pair : mp){
        for(int ele : pair.second){
            cout<<ele<<" ";
        }
        cout << endl;
    }

    return 0;
}