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

void kthhelper(Node* root , int level , int curr){
    if(root == NULL){
        return;
    }
    if(curr == level){
        cout<<root->data;
        return;
    }

    kthhelper(root->left,level,curr+1);
    kthhelper(root->right,level,curr+1);

}
void KthLevelOfTree(Node* root , int level ){
    
    kthhelper(root,level,1);
}

int main(){
    vector<int> arr = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root  = preOrderTree(arr);
    cout<<root->data;

    KthLevelOfTree(root,3);
    return 0;   
}