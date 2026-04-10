#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

vector<int> findSpiral(Node* root) {
    vector<int> res;
    if (root == NULL) return res;

    queue<Node*> q;
    q.push(root);

    bool reverseLevel = true; // start right -> left

    while (!q.empty()) {
        int n = q.size();
        vector<int> level;

        for (int i = 0; i < n; i++) {
            Node* curr = q.front();
            q.pop();

            level.push_back(curr->data);

            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }

        if (reverseLevel) {
            reverse(level.begin(), level.end());
        }

        for (int val : level) {
            res.push_back(val);
        }

        reverseLevel = !reverseLevel;
    }

    return res;
}

int main() {
    // Creating the tree:
    //      1
    //     / \
    //    3   2

    Node* root = new Node(1);
    root->left = new Node(3);
    root->right = new Node(2);

    vector<int> result = findSpiral(root);

    cout << "Spiral Traversal: ";
    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}