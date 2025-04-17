#include<iostream>
#include<vector>
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

pair<int,int> diameterOfTree(Node* root){
    if(root == NULL){
        return make_pair(0,0);
    }
    pair<int,int> left = diameterOfTree(root->left);
    pair<int,int> right = diameterOfTree(root->right);
    int currDiam = (left.second+right.second)+1;
    int Final = max(currDiam,max(left.first,right.first));
    int ht = max(left.second,right.second)+1;
    return make_pair(Final,ht);
}

int main(){
    vector<int> arr = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root  = preOrderTree(arr);
    pair<int,int> res = diameterOfTree(root);
    cout<<res.first<<" "<<res.second;
    cout<<diameterOfTree(root).first;
    return 0;   
}