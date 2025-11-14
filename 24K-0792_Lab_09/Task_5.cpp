#include <iostream>
using namespace std;

class Node {
public:
    int key;
    int height;
    Node* left;
    Node* right;

    Node(int val) {
        key = val;
        height = 1;
        left = right = NULL;
    }
};

int getHeight(Node* n) {
    return (n == NULL) ? 0 : n->height;
}

int getBalance(Node* n) {
    return (n == NULL) ? 0 : getHeight(n->left) - getHeight(n->right);
}

int maxH(int a, int b) {
    return (a > b) ? a : b;
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = maxH(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = maxH(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = maxH(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = maxH(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

Node* insertNode(Node* root, int key) {
    if (root == NULL)
        return new Node(key);

    if (key < root->key)
        root->left = insertNode(root->left, key);
    else if (key > root->key)
        root->right = insertNode(root->right, key);
    else
        return root;

    root->height = 1 + maxH(getHeight(root->left), getHeight(root->right));

    int bf = getBalance(root);

    if (bf > 1 && key < root->left->key)
        return rightRotate(root);

    if (bf < -1 && key > root->right->key)
        return leftRotate(root);

    if (bf > 1 && key > root->left->key) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (bf < -1 && key < root->right->key) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void printAVL(Node* root, int space = 0, int indent = 5) {
    if (root == NULL) return;

    space += indent;

    printAVL(root->right, space);
    cout<<endl;

    for (int i = indent; i < space; i++) cout<<" ";
    cout<<root->key<<" (h="<<root->height 
        <<", bf="<<getBalance(root)<<")";

    printAVL(root->left, space);
}

int main() {
    Node* root = NULL;

    int arr[] = {40, 30, 50, 25, 35, 45, 60};
    for (int x : arr)
        root = insertNode(root, x);

    cout<<"AVL Tree BEFORE inserting 55:\n";
    printAVL(root);
    cout<<"\n\n";

    root = insertNode(root, 55);

    cout<<"AVL Tree AFTER inserting 55:\n";
    printAVL(root);
    cout<<"\n";

    return 0;
}
