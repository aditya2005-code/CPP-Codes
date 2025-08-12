#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

int idx = -1;

TreeNode* preOrderTree(const vector<int>& arr) {
    idx++;
    if (idx >= arr.size() || arr[idx] == -1) {
        return NULL;
    }

    TreeNode* node = new TreeNode(arr[idx]);
    node->left = preOrderTree(arr);
    node->right = preOrderTree(arr);
    return node;
}

bool isValid(TreeNode* root, TreeNode* minNode, TreeNode* maxNode) {
    if (!root) return true;

    if (minNode && root->data <= minNode->data) return false;
    if (maxNode && root->data >= maxNode->data) return false;

    return isValid(root->left, minNode, root) && isValid(root->right, root, maxNode);
}

int rootSum(TreeNode* root) {
    if (!root) return 0;
    return root->data + rootSum(root->left) + rootSum(root->right);
}

int maxSumBST(TreeNode* root, int& globalMax) {
    if (!root) return 0;

    maxSumBST(root->left, globalMax);
    maxSumBST(root->right, globalMax);

    if (isValid(root, NULL, NULL)) {
        int total = rootSum(root);
        globalMax = max(globalMax, total);
    }

    return globalMax < 0 ? 0 : globalMax;
}

int main() {
    vector<int> arr = {1,4,3,2,4,2,5,-1,-1,-1,-1,-1,-1,4,6};

    idx = -1; 
    TreeNode* root = preOrderTree(arr);

    int maxSum = INT_MIN;
    cout << maxSumBST(root, maxSum) << endl; 
    return 0;
}
