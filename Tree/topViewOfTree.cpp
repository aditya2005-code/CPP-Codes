#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<unordered_map>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};
static int idx = -1;
Node* preOrderTree(vector<int> arr){
    idx++;
    if(arr[idx] == -1){
        return NULL;
    }
    Node* currNode = new Node(arr[idx]);
    currNode->left = preOrderTree(arr);
    currNode->right = preOrderTree(arr);

    return currNode;
}


void levelOrderTraversal(Node* root){

    queue<pair<Node*,int>> q;
    unordered_map<int,int> mp;
    q.push(make_pair(root,0));
    while(!q.empty()){
        pair<Node*,int> curr = q.front();
        q.pop();
        Node* node = curr.first;
        int currHd = curr.second;

        if(mp.count(currHd) == 0){
            mp[currHd] = node->data;
        }
        if(node->left != NULL){
            q.push(make_pair(node->left,currHd-1));
        }
        if(node->right != NULL){
            q.push(make_pair(node->right,currHd+1));

        }
    }
    for(const auto &pair : mp){
        cout<<pair.first<<" "<<pair.second<<endl;
    }
}

int main(){
    vector<int> arr = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root  = preOrderTree(arr);
    levelOrderTraversal(root);
    return 0;   
}