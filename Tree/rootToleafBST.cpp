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

void PrintArr(vector<int> path){
    for(int num : path){
        cout<<num<<" ";
    }
    cout<<endl;
}
void helper(Node* root , vector<int>& path){
    if(root == NULL){
        return;
    }
    path.push_back(root->data);
    if(root->left == NULL && root->right == NULL){
        PrintArr(path);
        path.pop_back();
        return;
    }
    helper(root->left,path);
    helper(root->right,path);
    path.pop_back();
}
void RootToLeafBST(Node* root){
    if(root == NULL){
        return;
    }
    vector<int> path;
    helper(root,path);
}
int main(){
    vector<int> arr = {8,5,3,1,4,6,10,11,14};
    Node* root = constructBST(arr);
    inOrder(root);
    RootToLeafBST(root);
    return 0;
}
