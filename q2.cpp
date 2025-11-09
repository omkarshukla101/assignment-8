#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class BST {
public:
    Node* root;
    BST() {
        root = NULL;
    }

    Node* insert(Node* node, int val) {
        if (!node) return new Node(val);
        if (val < node->data)
            node->left = insert(node->left, val);
        else
            node->right = insert(node->right, val);
        return node;
    }

    Node* searchRecursive(Node* node, int key) {
        if (!node || node->data == key)
            return node;
        if (key < node->data)
            return searchRecursive(node->left, key);
        return searchRecursive(node->right, key);
    }

    Node* searchNonRecursive(Node* node, int key) {
        while (node) {
            if (node->data == key)
                return node;
            if (key < node->data)
                node = node->left;
            else
                node = node->right;
        }
        return NULL;
    }

    Node* findMin(Node* node) {
        while (node && node->left)
            node = node->left;
        return node;
    }

    Node* findMax(Node* node) {
        while (node && node->right)
            node = node->right;
        return node;
    }

    Node* inorderSuccessor(Node* root, Node* x) {
        if (x->right) return findMin(x->right);
        Node* succ = NULL;
        while (root) {
            if (x->data < root->data) {
                succ = root;
                root = root->left;
            } else if (x->data > root->data)
                root = root->right;
            else break;
        }
        return succ;
    }

    Node* inorderPredecessor(Node* root, Node* x) {
        if (x->left) return findMax(x->left);
        Node* pred = NULL;
        while (root) {
            if (x->data > root->data) {
                pred = root;
                root = root->right;
            } else if (x->data < root->data)
                root = root->left;
            else break;
        }
        return pred;
    }

    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
};

int main() {
    BST tree;
    tree.root = tree.insert(tree.root, 20);
    tree.insert(tree.root, 10);
    tree.insert(tree.root, 30);
    tree.insert(tree.root, 5);
    tree.insert(tree.root, 15);
    tree.insert(tree.root, 25);
    tree.insert(tree.root, 35);

    cout << "Inorder Traversal: ";
    tree.inorder(tree.root);
    cout << endl;

    int key = 15;
    Node* r = tree.searchRecursive(tree.root, key);
    cout << "Recursive Search " << key << ": " << (r ? "Found" : "Not Found") << endl;

    Node* nr = tree.searchNonRecursive(tree.root, key);
    cout << "Non-Recursive Search " << key << ": " << (nr ? "Found" : "Not Found") << endl;

    cout << "Minimum Element: " << tree.findMin(tree.root)->data << endl;
    cout << "Maximum Element: " << tree.findMax(tree.root)->data << endl;

    Node* x = tree.searchRecursive(tree.root, 25);
    Node* succ = tree.inorderSuccessor(tree.root, x);
    Node* pred = tree.inorderPredecessor(tree.root, x);

    cout << "Inorder Successor of " << x->data << ": " << (succ ? to_string(succ->data) : "None") << endl;
    cout << "Inorder Predecessor of " << x->data << ": " << (pred ? to_string(pred->data) : "None") << endl;
}
