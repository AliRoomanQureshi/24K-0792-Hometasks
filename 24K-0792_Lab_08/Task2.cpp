#include <iostream>

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

int cNodes(Node* root) {
	if (root==nullptr) {
		return 0;
	}
	return 1 + cNodes(root->left) + cNodes(root->right);
}

int cLeaves(Node* root) {
	if (root==nullptr) {
		return 0;
	}
	if (root->left==nullptr && root->right==nullptr) {
		return 1;
	}
	return cLeaves(root->left) + cLeaves(root->right);
}

int findHeight(Node* root) {
	if (root==nullptr) {
		return 0;
	}

	int leftHeight=findHeight(root->left);
	int rightHeight=findHeight(root->right);

	int maxHeight=(leftHeight > rightHeight) ? leftHeight : rightHeight;

	return 1 + maxHeight;
}

int main() {
	Node* root=new Node(10);
	root->left=new Node(5);
	root->right=new Node(15);
	root->left->left=new Node(3);
	root->left->right=new Node(7);
	root->right->right=new Node(18);
	root->left->left->left=new Node(1);

	cout<<"Binary Tree Analysis"<<endl;
	

	cout<<"Total Nodes: "<<cNodes(root)<<endl;
	cout<<"Leaf Nodes: "<<cLeaves(root)<<endl;
	cout<<"Tree Height: "<<findHeight(root)<<endl;

	return 0;
}
