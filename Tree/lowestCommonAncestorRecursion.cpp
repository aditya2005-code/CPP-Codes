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


Node* lowestCommonAncestor(Node* root , int n1 , int n2){
    if(root == NULL){
        return NULL;
    }
    if(root->data == n1 || root->data == n2){
        return root;
    }

    Node* left = lowestCommonAncestor(root->left,n1,n2);
    Node* right = lowestCommonAncestor(root->right,n1,n2);

    if(right != NULL && left != NULL){
        return root;
    }

    return left==NULL? right : left;
}

int main(){
    vector<int> arr = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root  = preOrderTree(arr);
    // cout<<root->data;
    Node* res = lowestCommonAncestor(root,4,5);
    cout<<res->data;
    return 0;   
}