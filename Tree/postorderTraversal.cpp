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

void postOrderTraversal(Node* root){
    if(root == NULL){
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<<root->data<<"->";
}

int main(){
    vector<int> arr = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root  = preOrderTree(arr);
    postOrderTraversal(root);
    return 0;   
}