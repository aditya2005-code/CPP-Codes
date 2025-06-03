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

bool searchBST(Node* root , int target){
    if(root == NULL){
        return false;
    }
    if(root->data == target){
        return root;
    }
    if(target > root->data){
        return searchBST(root->right,target);
    }
    else{
        return searchBST(root->left,target);
    }
    return false;
}
int main(){
    vector<int> arr = {4,2,5,1,3,6};
    Node* root = constructBST(arr);
    cout<< searchBST(root,3);
    return 0;
}
