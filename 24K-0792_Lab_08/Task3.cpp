#include <iostream>
using namespace std;

class Node {
public:
    string levelName;
    Node* left;
    Node* right;

    Node(string name) {
        levelName=name;
        left=nullptr;
        right=nullptr;
    }
};

bool isFullBinaryTree(Node* root) {
    if (root == nullptr)
        return true;
    if (root->left == nullptr && root->right == nullptr)
        return true;
    if (root->left != nullptr && root->right != nullptr)
        return isFullBinaryTree(root->left) && isFullBinaryTree(root->right);
    return false;
}

int main() {
    Node* root=new Node("Level 1");
    root->left=new Node("Level 2");
    root->right=new Node("Level 3");
    root->left->left=new Node("Level 4");
    root->left->right=new Node("Level 5");
    root->right->left=new Node("Level 6");
    root->right->right=new Node("Level 7");

    cout<<"Checking if the game level structure is a Full Binary Tree..."<<endl;

    if (isFullBinaryTree(root))
        cout<<"The given tree is a Full Binary Tree. The levels are symmetrically balanced for gameplay."<<endl;
    else
        cout<<"The given tree is NOT a Full Binary Tree. Some levels have missing sub-levels."<<endl;

    return 0;
}
