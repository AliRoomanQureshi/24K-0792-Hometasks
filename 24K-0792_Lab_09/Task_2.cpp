#include <iostream>
using namespace std;

class Node {
public:
    int key;
    Node *left;
    Node *right;
    int height;
};

class AVLTree {
public:

    int height(Node *node) {
        return (node == nullptr) ? 0 : node->height;
    }

    int maxValue(int a, int b) {
        return (a > b) ? a : b;
    }

    Node* createNode(int key) {
        Node* node = new Node();
        node->key = key;
        node->left = nullptr;
        node->right = nullptr;
        node->height = 1;
        return node;
    }

    Node* rotateRight(Node *y) {
        Node *x = y->left;
        Node *sub = x->right;

        x->right = y;
        y->left = sub;

        y->height = 1 + maxValue(height(y->left), height(y->right));
        x->height = 1 + maxValue(height(x->left), height(x->right));

        return x;
    }

    Node* rotateLeft(Node *x) {
        Node *y = x->right;
        Node *sub = y->left;

        y->left = x;
        x->right = sub;

        x->height = 1 + maxValue(height(x->left), height(x->right));
        y->height = 1 + maxValue(height(y->left), height(y->right));

        return y;
    }

    int getBalance(Node *node) {
        return (node == nullptr) ? 0 : height(node->left) - height(node->right);
    }

    Node* insert(Node* node, int key) {

        if (node == nullptr)
            return createNode(key);

        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);
        else
            return node;

        node->height = 1 + maxValue(height(node->left), height(node->right));

        int balance = getBalance(node);

        if (balance > 1 && key < node->left->key)
            return rotateRight(node);

        if (balance < -1 && key > node->right->key)
            return rotateLeft(node);

        if (balance > 1 && key > node->left->key) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        if (balance < -1 && key < node->right->key) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    void preOrder(Node *root) {
        if (root) {
            cout<<root->key<<" ";
            preOrder(root->left);
            preOrder(root->right);
        }
    }
};

int main() {
    AVLTree avl;
    Node *root = nullptr;

    root = avl.insert(root, 50);
    root = avl.insert(root, 30);
    root = avl.insert(root, 70);
    root = avl.insert(root, 20);
    root = avl.insert(root, 40);
    root = avl.insert(root, 60);
    root = avl.insert(root, 80);

    cout<<"Initial tree (pre-order):\n";
    avl.preOrder(root);
    cout<<"\n\n";

    root = avl.insert(root, 55);

    cout<<"Tree after inserting 55 (pre-order):\n";
    avl.preOrder(root);
    cout<<"\n\n";

    cout<<"Tree after manually applying a Left Rotation on the root:\n";
    root = avl.rotateLeft(root);
    avl.preOrder(root);
    cout<<"\n";

    return 0;
}
