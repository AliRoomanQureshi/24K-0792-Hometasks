#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data=val;
        left=right=nullptr;
    }
};

class CompleteBinaryTree {
private:
    Node* root;

    int findSubtreeSum(Node* node, int target, bool &found) {
        if (!node) return 0;

        int leftSum=findSubtreeSum(node->left, target, found);
        int rightSum=findSubtreeSum(node->right, target, found);

        int total=node->data + leftSum + rightSum;

        if (total == target && !found) {
            cout<<"\nSubtree with target sum "<<target<<" found:\n";
            displaySubtree(node);
            found=true;
        }

        return total;
    }

    void displaySubtree(Node* node) {
        if (!node) return;
        cout<<node->data<<" ";
        displaySubtree(node->left);
        displaySubtree(node->right);
    }

public:
    CompleteBinaryTree() {
        root=nullptr;
    }

    void buildTree(int n) {
        if (n <= 0) return;

        queue<Node*> q;
        int value;
        cout<<"Enter value for root: ";
        cin >> value;

        root=new Node(value);
        q.push(root);

        for (int i=1; i < n; i++) {
            Node* parent=q.front();

            cout<<"Enter value for node "<<i + 1<<": ";
            cin >> value;

            Node* newNode=new Node(value);
            if (!parent->left)
                parent->left=newNode;
            else {
                parent->right=newNode;
                q.pop();
            }

            q.push(newNode);
        }
    }

    void checkSubtreeWithSum(int target) {
        if (!root) {
            cout<<"Tree is empty.\n";
            return;
        }

        bool found=false;
        findSubtreeSum(root, target, found);
        if (!found)
            cout<<"\nNo subtree with sum "<<target<<" found.\n";
    }
};

int main() {
    CompleteBinaryTree tree;
    int n, target;

    cout<<"Enter number of nodes in complete binary tree: ";
    cin>>n;

    tree.buildTree(n);

    cout<<"\nEnter target sum to find: ";
    cin>>target;

    tree.checkSubtreeWithSum(target);

    return 0;
}
