#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
typedef struct Node {
    int key;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node
Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node in the BST
Node* insert(Node* root, int key) {
    if (root == NULL) {
        return createNode(key);
    }
    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    }
    return root;
}

// Function to find the minimum value node in a BST
Node* findMin(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to delete a node in the BST
Node* deleteNode(Node* root, int key) {
    if (root == NULL) {
        return root;
    }
    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        Node* temp = findMin(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

// Function for in-order traversal (Left, Root, Right)
void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->key);
        inOrder(root->right);
    }
}

// Function for pre-order traversal (Root, Left, Right)
void preOrder(Node* root) {
    if (root != NULL) {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Function for post-order traversal (Left, Right, Root)
void postOrder(Node* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->key);
    }
}

// Function to count total number of nodes
int countNodes(Node* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Function to count internal nodes
int countInternalNodes(Node* root) {
    if (root == NULL || (root->left == NULL && root->right == NULL)) {
        return 0;
    }
    return 1 + countInternalNodes(root->left) + countInternalNodes(root->right);
}

// Function to count external nodes (leaf nodes)
int countExternalNodes(Node* root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    return countExternalNodes(root->left) + countExternalNodes(root->right);
}

// Function to find the height of the tree
int findHeight(Node* root) {
    if (root == NULL) {
        return -1;
    }
    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

// Function to find the smallest node in the BST
Node* findMinNode(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to find the largest node in the BST
Node* findMaxNode(Node* root) {
    while (root->right != NULL) {
        root = root->right;
    }
    return root;
}

// Main function to test the implementation
int main() {
    Node* root = NULL;

    // Insert nodes
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    // Traversals
    printf("In-order Traversal: ");
    inOrder(root);
    printf("\n");

    printf("Pre-order Traversal: ");
    preOrder(root);
    printf("\n");

    printf("Post-order Traversal: ");
    postOrder(root);
    printf("\n");

    // Node Counts
    printf("Total Nodes: %d\n", countNodes(root));
    printf("Internal Nodes: %d\n", countInternalNodes(root));
    printf("External Nodes: %d\n", countExternalNodes(root));

    // Height of the tree
    printf("Height of the Tree: %d\n", findHeight(root));

    // Smallest and Largest Nodes
    printf("Smallest Node: %d\n", findMinNode(root)->key);
    printf("Largest Node: %d\n", findMaxNode(root)->key);

    // Delete a node
    printf("Deleting 20\n");
    root = deleteNode(root, 20);
    printf("In-order Traversal after deletion: ");
    inOrder(root);
    printf("\n");

    return 0;
}