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


class Info{
    public:
    bool isBst;
    int min;
    int max;
    int size;

    Info(bool isBst , int min , int max , int size){
        this->isBst = isBst;
        this->max = max;
        this->min = min;
        this->size = size;
    }
};

static int maxsz;

Info* sizeOfLargest(Node* root){
    if(root == NULL){
        return new Info(true,INT16_MAX,INT16_MIN,0);
    }
    Info* leftInfo = sizeOfLargest(root->left);
    Info* rightInfo = sizeOfLargest(root->right);

    int currMin = min(root->data,min(leftInfo->min,rightInfo->min));
    int currMax = max(root->data,max(leftInfo->max,rightInfo->max));
    int currsz= leftInfo->size+rightInfo->size+1;

    if(leftInfo->isBst && rightInfo->isBst
    && root->data > leftInfo->max && 
    root->data < rightInfo->min){
        maxsz = max(maxsz,currsz);
        return new Info(true,currMin,currMax,currsz);
    }

    return new Info(false,currMin,currMax,currsz);
}

int main(){
    Node* root = new Node(50);
    root->left = new Node(30);
    root->left->left = new Node(5);
    root->left->right = new Node(20);
    
    root->right = new Node(60);
    root->right->left = new Node(45);
    root->right->right = new Node(70);
    root->right->right->left = new Node(65);
    root->right->right->right = new Node(80);

    sizeOfLargest(root);
    cout<<maxsz;
    return 0;   
}