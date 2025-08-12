#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class TreeNode{
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

int heightOfTree(TreeNode* root){
    if(root == NULL){
        return 0;
    }
    int left = heightOfTree(root->left);
    int right = heightOfTree(root->right);
    int ht = max(left,right)+1;
    return ht;
}

TreeNode* insert(TreeNode* root , int val){
    if(root == NULL){
        root = new TreeNode(val);
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
TreeNode* constructBST(vector<int> arr ){
    TreeNode* root = NULL;

    for(int i=0 ; i<arr.size() ; i++){
       root =  insert(root,arr[i]);
    }
    return root;
}

void inOrder(TreeNode* root){
    if(root == NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<"-> ";
    inOrder(root->right);
}

    void inOrder(TreeNode* root ,vector<int>& nums){
        if(root == NULL){
            return;
        }
        inOrder(root->left,nums);
        nums.push_back(root->data);
        inOrder(root->right,nums);
    }
    TreeNode* insertBST(vector<int> nums , int si , int ei){
        if(si > ei){
            return NULL;
        }
        int mid = si+(ei-si)/2;
        TreeNode* curr = new TreeNode(nums[mid]);
        curr->left = insertBST(nums,si,mid-1);
        curr->right = insertBST(nums,mid+1,ei);
        return curr;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> nums;
        inOrder(root,nums);
        return insertBST(nums,0,nums.size()-1);
    }
int main(){
    vector<int> arr = {8,5,3,1,4,6,10,11,14};
    vector<int> nums = {1,2,3,4,5,6,7};
    TreeNode* root = constructBST(arr);
    cout<<heightOfTree(root);
    cout<<endl;
    inOrder(root);
    cout<<endl;
    TreeNode* r = balanceBST(root);
    cout<<heightOfTree(r)<<endl;
    inOrder(r);
    return 0;
}
