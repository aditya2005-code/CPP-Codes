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

bool isIdentical(Node* root, Node* subRoot){
    if(root == NULL && subRoot == NULL){
        return true;
    }
    else if(root == NULL || subRoot == NULL){
        return false;
    }
    if(root->data != subRoot->data){
        return false;
    }
    return isIdentical(root->left,subRoot->left) && isIdentical(root->right,subRoot->right);
    
}

bool isSubtree(Node* root , Node* subRoot){
    if(root == NULL && subRoot == NULL){
        return true;
    }
    else if(root == NULL || subRoot == NULL){
        return false;
    }
    if(root->data == subRoot->data){
        if(isIdentical(root,subRoot)) return true;
    }
    bool leftSubtree = isSubtree(root->left,subRoot);
    if(!leftSubtree){
        return isSubtree(root->right,subRoot);
    }

    return true;
}

int main(){
    vector<int> arr = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root  = preOrderTree(arr);
    
    Node* subRoot = new Node(2);
    subRoot->left = new Node(4);
    subRoot->right = new Node(5);
    
    cout<<isSubtree(root,subRoot);
    return 0;   
}