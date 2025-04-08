#include<iostream>
#include<vector>
#include<queue>
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

void levelOrderTraversal(Node* root){
    if(root == NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){

        Node* currNode = q.front();
        q.pop();
       if(currNode == NULL) {
            
        cout<<endl;
        if(q.empty()){
            break;
        }
        q.push(NULL);
        }
        else{
            cout<<currNode->data<<" ->";
            if(currNode->left != NULL){
            q.push(currNode->left);
            }
            if(currNode->right != NULL){
                q.push(currNode->right);
            }
        }
    }
}

int main(){
    vector<int> arr = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root  = preOrderTree(arr);
    levelOrderTraversal(root);
    return 0;   
}