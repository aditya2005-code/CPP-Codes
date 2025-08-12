#include <iostream>
using namespace std;

enum Color { RED, BLACK };

struct Node {
    int data;
    Color color;
    Node *left, *right, *parent;

    Node(int data) : data(data), color(RED), left(nullptr), right(nullptr), parent(nullptr) {}
};

class RBTree {
    Node* root;

    void rotateLeft(Node* &root, Node* x) {
        Node* y = x->right;
        x->right = y->left;
        if (y->left != nullptr)
            y->left->parent = x;
        
        y->parent = x->parent;
        if (x->parent == nullptr)
            root = y;
        else if (x == x->parent->left)
            x->parent->left = y;
        else
            x->parent->right = y;
        
        y->left = x;
        x->parent = y;
    }

    void rotateRight(Node* &root, Node* y) {
        Node* x = y->left;
        y->left = x->right;
        if (x->right != nullptr)
            x->right->parent = y;
        
        x->parent = y->parent;
        if (y->parent == nullptr)
            root = x;
        else if (y == y->parent->left)
            y->parent->left = x;
        else
            y->parent->right = x;
        
        x->right = y;
        y->parent = x;
    }

    void fixInsertRBTree(Node* &root, Node* &pt) {
        Node* parent_pt = nullptr;
        Node* grandparent_pt = nullptr;

        while (pt != root && pt->color == RED && pt->parent->color == RED) {
            parent_pt = pt->parent;
            grandparent_pt = pt->parent->parent;

            // Case A: Parent is left child of grandparent
            if (parent_pt == grandparent_pt->left) {
                Node* uncle_pt = grandparent_pt->right;

                // Case 1: Uncle is red (recoloring)
                if (uncle_pt != nullptr && uncle_pt->color == RED) {
                    grandparent_pt->color = RED;
                    parent_pt->color = BLACK;
                    uncle_pt->color = BLACK;
                    pt = grandparent_pt;
                } else {
                    // Case 2: pt is right child (left rotation needed)
                    if (pt == parent_pt->right) {
                        rotateLeft(root, parent_pt);
                        pt = parent_pt;
                        parent_pt = pt->parent;
                    }
                    // Case 3: pt is left child (right rotation needed)
                    rotateRight(root, grandparent_pt);
                    swap(parent_pt->color, grandparent_pt->color);
                    pt = parent_pt;
                }
            }
            // Case B: Parent is right child of grandparent
            else {
                Node* uncle_pt = grandparent_pt->left;

                // Case 1: Uncle is red (recoloring)
                if (uncle_pt != nullptr && uncle_pt->color == RED) {
                    grandparent_pt->color = RED;
                    parent_pt->color = BLACK;
                    uncle_pt->color = BLACK;
                    pt = grandparent_pt;
                } else {
                    // Case 2: pt is left child (right rotation needed)
                    if (pt == parent_pt->left) {
                        rotateRight(root, parent_pt);
                        pt = parent_pt;
                        parent_pt = pt->parent;
                    }
                    // Case 3: pt is right child (left rotation needed)
                    rotateLeft(root, grandparent_pt);
                    swap(parent_pt->color, grandparent_pt->color);
                    pt = parent_pt;
                }
            }
        }
        root->color = BLACK;
    }

    void inorderHelper(Node* root) {
        if (root == nullptr)
            return;
        inorderHelper(root->left);
        cout << root->data << (root->color == RED ? "(R) " : "(B) ");
        inorderHelper(root->right);
    }

public:
    RBTree() : root(nullptr) {}

    void insert(const int &data) {
        Node* pt = new Node(data);

        // BST insert
        Node* parent = nullptr;
        Node* current = root;

        while (current != nullptr) {
            parent = current;
            if (pt->data < current->data)
                current = current->left;
            else
                current = current->right;
        }

        pt->parent = parent;

        if (parent == nullptr)
            root = pt;  // Tree was empty
        else if (pt->data < parent->data)
            parent->left = pt;
        else
            parent->right = pt;

        // Fix red-black tree violations
        fixInsertRBTree(root, pt);
    }

    void inorder() {
        inorderHelper(root);
        cout << "\n";
    }
};

int main() {
    RBTree tree;

    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(15);
    tree.insert(25);
    tree.insert(5);
    tree.insert(1);

    cout << "Inorder traversal of Red-Black Tree:\n";
    tree.inorder();

    return 0;
}
