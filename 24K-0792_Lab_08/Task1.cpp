#include <iostream>
#include <string>
using namespace std;

class Node {
	public:
		string name;
		Node* left;
		Node* right;

		Node(string n) : name(n), left(nullptr), right(nullptr) {}
};

class TourTree {
	public:
		Node* root;

		TourTree() {
			root = nullptr;
		}

		void addPackageIterative(Node* startNode, string name) {
			Node* current = startNode;

			while (true) {
				char choice;
				cout<<"Add "<<name<<" to left or right of "<<current->name<<"? (l/r): ";
				cin >> choice;

				if (choice == 'l') {
					if (current->left == nullptr) {
						current->left = new Node(name);
						return;
					} else {
						current = current->left;
					}
				} else {
					if (current->right == nullptr) {
						current->right = new Node(name);
						return;
					} else {
						current = current->right;
					}
				}
			}
		}

		Node* addPackage(Node* root, string name) {
			if (root == nullptr) {
				root = new Node(name);
				return root;
			}
			char choice;
			cout<<"Add "<<name<<" to left or right of "<<root->name<<"? (l/r): ";
			cin >> choice;
			if (choice == 'l')
				root->left = addPackage(root->left, name);
			else
				root->right = addPackage(root->right, name);
			return root;
		}

		void display(Node* root, int space = 0) {
			if (root == nullptr)
				return;
			space += 5;
			display(root->right, space);
			cout<<endl;
			for (int i = 5; i < space; i++)
				cout<<" ";
			cout<<root->name<<endl;
			display(root->left, space);
		}
};

int main() {
	TourTree tree;
	int n;
	string name;
	cout<<"Enter number of tour packages: ";
	cin >> n;
	cin.ignore();
	
	for (int i = 0; i < n; i++) {
		cout<<"Enter package name: ";
		getline(cin, name);
		
		if (tree.root == nullptr)
			tree.root = new Node(name);
		else
			tree.addPackageIterative(tree.root, name); 
	}
	
	cout<<"\nTour Package Hierarchy:\n";
	tree.display(tree.root);
	return 0;
}
