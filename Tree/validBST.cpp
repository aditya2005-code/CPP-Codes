#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* insert(Node* root , int val){
    if(root == NULL){
        root = new Node(val);
        return root;
    }
    if(root->data > val){
        root->left = insert(root->left,val);
    }
    else{
        root->right = insert(root->right,val);
    }
    return root;
}
Node* constructBST(vector<int> arr ){
    Node* root = NULL;

    for(int i=0 ; i<arr.size() ; i++){
       root =  insert(root,arr[i]);
    }
    return root;
}

void inOrder(Node* root){
    if(root == NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<"-> ";
    inOrder(root->right);
}

bool validBST(Node* root , Node* min , Node* max){
    if(root == NULL){
        return true;
    }
    if(max != NULL && root->data > max->data){
        return false;
    }
    if(min != NULL && root->data < min->data){
        return false;
    }
    return validBST(root->left,min,root)&&validBST(root->right,root,max);
    
}
int main(){
    vector<int> arr = {8,5,3,1,4,6,10,11,14};
    Node* root = constructBST(arr);
    inOrder(root);
    cout<<validBST(root,NULL,NULL);
    return 0;
}
