#include <iostream>
using namespace std;

class Node {
public:
    int key;
    Node* left;
    Node* right;
    int height;

    Node(int k) {
        key = k;
        left = right = NULL;
        height = 1;
    }
};

int height(Node* n) {
    return (n == NULL ? 0 : n->height);
}

int updateHeight(Node* n) {
    return 1 + max(height(n->left), height(n->right));
}

int getBalance(Node* n) {
    return (n == NULL ? 0 : height(n->left) - height(n->right));
}

Node* rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = updateHeight(y);
    x->height = updateHeight(x);

    return x;
}

Node* rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = updateHeight(x);
    y->height = updateHeight(y);

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

    root->height = updateHeight(root);
    int balance = getBalance(root);

    if (balance > 1 && key < root->left->key)
        return rotateRight(root);

    if (balance < -1 && key > root->right->key)
        return rotateLeft(root);

    if (balance > 1 && key > root->left->key) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    if (balance < -1 && key < root->right->key) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

Node* minValueNode(Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

Node* deleteNode(Node* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL || root->right == NULL) {
            Node* temp = root->left ? root->left : root->right;
            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else {
                *root = *temp;
            }
            delete temp;
        } else {
            Node* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }

    if (root == NULL)
        return root;

    root->height = updateHeight(root);
    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0)
        return rotateRight(root);

    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0)
        return rotateLeft(root);

    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout<<root->key<<" ";
    inorder(root->right);
}

void printTree(Node* root, int space = 0, int height = 10) {
    if (root == NULL) return;

    space += height;

    printTree(root->right, space);
    cout<<endl;

    for (int i = height; i < space; i++)
        cout<<" ";
    cout<<root->key<<"\n";

    printTree(root->left, space);
}

int main() {
    Node* root = NULL;

    int values[] = {100, 80, 120, 70, 90, 110, 130};

    for (int x : values)
        root = insertNode(root, x);

    cout<<"Original Tree:\n";
    printTree(root);
    cout<<"\n";

    root = deleteNode(root, 80);

    cout<<"After Deleting 80:\n";
    printTree(root);
    cout<<"\n";

    cout<<"Inorder: ";
    inorder(root);
    cout<<"\n";

    return 0;
}
