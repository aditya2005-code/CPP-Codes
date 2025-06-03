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

Node* insertNode(vector<int>& nums, int si , int ei) {
        if(si > ei){
            return NULL;
        }
        int mid = si+(ei-si)/2;
        Node* curr = new Node(nums[mid]);
        curr->left = insertNode(nums,si,mid-1);
        curr->right = insertNode(nums,mid+1,ei);
        return curr;
    }
Node* sortedArrayToBST(vector<int>& nums) {
    return insertNode(nums,0,nums.size()-1);
}
int main(){
    vector<int> arr = {8,5,3,1,4,6,10,11,14};
    vector<int> nums = {1,2,3,4,5,6,7};
    Node* root = constructBST(arr);
    inOrder(root);
    cout<<endl;
    Node* r = sortedArrayToBST(nums);
    inOrder(r);
    return 0;
}
