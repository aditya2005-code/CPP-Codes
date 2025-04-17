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
int heightOfTree(Node* root){
    if(root == NULL){
        return 0;
    }
    int left = heightOfTree(root->left);
    int right = heightOfTree(root->left);
    int ans = max(left,right)+1; 
    return ans;
}
int diameterOfTree(Node* root){
    if(root == NULL){
        return 0;
    }
    int curr = heightOfTree(root->left)+heightOfTree(root->right)+1;
    int left = heightOfTree(root->left);
    int right = heightOfTree(root->right);
    return max(left,max(right,curr))+1;
}

int main(){
    vector<int> arr = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root  = preOrderTree(arr);
    cout<<diameterOfTree(root);
    return 0;   
}