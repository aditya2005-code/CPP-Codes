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

    path.push_back(root->data);

    if(root->data == n){
        return true;
    }
    int left = pathNode(root->left,n,path);
    int right = pathNode(root->right,n,path);

    if(left || right){
        return true;
    }
    path.pop_back();
    return false;
}
int lowestCommonAncestor(Node* root1 , int n1 , int n2){
    if(root1 == NULL){
        return -1;
    }
    vector<int> path1 , path2;
    pathNode(root1 , n1 , path1);
    pathNode(root1,n2,path2);

    int res = -1;
    for(int i=0 , j = 0; i<path1.size() , j < path2.size() ; i++ , j++){
        if(path1[i] != path2[j]){
            return res;
        }
        res = path1[i];
    }
    return res;
}

int main(){
    vector<int> arr = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root  = preOrderTree(arr);
    // cout<<root->data;
    int res = lowestCommonAncestor(root,4,5);
    cout<<res;
    return 0;   
}