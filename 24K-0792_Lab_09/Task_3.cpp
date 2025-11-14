#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* leftChild;
    Node* rightChild;
    int height;
};

class AVL {
public:

    int getHeight(Node* node) {
        return (node == nullptr) ? 0 : node->height;
    }

    int bigger(int a, int b) {
        return (a > b) ? a : b;
    }

    Node* createNode(int value) {
        Node* temp = new Node();
        temp->value = value;
        temp->leftChild = nullptr;
        temp->rightChild = nullptr;
        temp->height = 1;
        return temp;
    }

    Node* rotateRight(Node* y) {
        Node* x = y->leftChild;
        Node* subtree = x->rightChild;

        x->rightChild = y;
        y->leftChild = subtree;

        y->height = bigger(getHeight(y->leftChild), getHeight(y->rightChild)) + 1;
        x->height = bigger(getHeight(x->leftChild), getHeight(x->rightChild)) + 1;

        return x;
    }

    Node* rotateLeft(Node* x) {
        Node* y = x->rightChild;
        Node* subtree = y->leftChild;

        y->leftChild = x;
        x->rightChild = subtree;

        x->height = bigger(getHeight(x->leftChild), getHeight(x->rightChild)) + 1;
        y->height = bigger(getHeight(y->leftChild), getHeight(y->rightChild)) + 1;

        return y;
    }

    int balanceFactor(Node* node) {
        if (node == nullptr) return 0;
        return getHeight(node->leftChild) - getHeight(node->rightChild);
    }

    Node* insert(Node* root, int value) {
        if (root == nullptr)
            return createNode(value);

        if (value < root->value)
            root->leftChild = insert(root->leftChild, value);
        else if (value > root->value)
            root->rightChild = insert(root->rightChild, value);
        else
            return root;

        root->height = 1 + bigger(getHeight(root->leftChild), getHeight(root->rightChild));

        int bf = balanceFactor(root);

        if (bf > 1 && value < root->leftChild->value)
            return rotateRight(root);

        if (bf < -1 && value > root->rightChild->value)
            return rotateLeft(root);

        if (bf > 1 && value > root->leftChild->value) {
            root->leftChild = rotateLeft(root->leftChild);
            return rotateRight(root);
        }

        if (bf < -1 && value < root->rightChild->value) {
            root->rightChild = rotateRight(root->rightChild);
            return rotateLeft(root);
        }

        return root;
    }

    void preorder(Node* root) {
        if (root != nullptr) {
            cout<<root->value<<" ";
            preorder(root->leftChild);
            preorder(root->rightChild);
        }
    }
};

int main() {

    AVL tree;
    Node* root = nullptr;

    root = tree.insert(root, 10);
    root = tree.insert(root, 5);
    root = tree.insert(root, 15);
    root = tree.insert(root, 3);
    root = tree.insert(root, 7);

    cout<<"Initial AVL Tree (Preorder):\n";
    tree.preorder(root);
    cout<<"\n\n";

    root = tree.insert(root, 12);

    cout<<"Tree after inserting 12 (Preorder):\n";
    tree.preorder(root);
    cout<<"\n\n";

    cout<<"Height of final tree: "<<tree.getHeight(root)<<"\n";

    return 0;
}
