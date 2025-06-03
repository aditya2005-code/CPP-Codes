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

Node* inorderSuccessor(Node* root){
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}

Node* deleteNodebST(Node* root , int val){
    if(root == NULL){
        return NULL;
    }

    if(val < root->data){
        root->left = deleteNodebST(root->left,val);
    }
    else if(val > root->data){
        root->right = deleteNodebST(root->right,val);
    }
    else{
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        if(root->left == NULL || root->right == NULL){
            return root->left == NULL?root->right:root->left;
        }
        Node* isu = inorderSuccessor(root->right);
        root->data = isu->data;
        root->right = deleteNodebST(root->right,isu->data);
        return root;
    }
    return root;
}
int main(){
    vector<int> arr = {8,5,3,1,4,6,10,11,14};
    Node* root = constructBST(arr);
    inOrder(root);
    cout<<endl;
    deleteNodebST(root,4);
    inOrder(root);
    return 0;
}
