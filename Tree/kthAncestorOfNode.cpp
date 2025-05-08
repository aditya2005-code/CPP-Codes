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

bool pathNode(Node* root , int n , vector<int> &path){
    if(root == NULL){
        return false;
    }

    
    if(root->data == n){
        return true;
    }
    path.push_back(root->data);
    int left = pathNode(root->left,n,path);
    int right = pathNode(root->right,n,path);

    if(left || right){
        return true;
    }
    path.pop_back();
    return false;
}

int kthAncestorNode(Node* root , int n , int k){
    vector<int> res;
    pathNode(root,n,res);
    int idx = res.size()-k;
    if( idx < 0) return -1;
    return res[idx];
}

int kthAncestor2(Node* root , int n , int k){
    if(root == NULL){
        return -1;
    }

    if(root->data == n){
        return 0;
    }

    int left = kthAncestor2(root->left,n,k);
    int right = kthAncestor2(root->right,n,k);
    if(right == -1 && left == -1){
        return -1;
    }

    int valid = left == -1 ? right : left;
    if(valid+1 == k){
        cout << root->data;
    }

    return valid + 1;
}

int main(){
    vector<int> arr = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root  = preOrderTree(arr);
    // cout<<root->data;
    int res = kthAncestorNode(root,6,2);
    cout<<res;
    kthAncestor2(root,6,2);
    return 0;   
}