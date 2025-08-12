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

bool isST(Node* root1 , Node* root2){
    if(root1 == NULL && root2 == NULL){
        return true;
    }

    if(root1 != NULL && root2 == NULL && root1 == NULL && root2 != NULL){
        return false;
    }

    if(root1->data != root2->data){
        return false;
    }

    int left = isST(root1->left , root2->right);
    int right = isST(root1->right , root2->left);

    return  left && right;
}

bool isSymmetric(Node* root){
    if(root == NULL){
        return true;
    }

    return isST(root->left,root->right);

}

int main(){
    vector<int> arr = {1, 2, 3, -1, -1, 4, -1, -1, 2, 4, -1, -1, 3, -1, -1};

    Node* root  = preOrderTree(arr);
    // cout<<root->data;
    bool isS = isSymmetric(root);
    cout<<isS;
   
    return 0;   
}