#include <iostream>
using namespace std;

class ProductNode {
public:
    int id;
    int qty;
    ProductNode* left;
    ProductNode* right;

    ProductNode(int i, int q) {
        id = i;
        qty = q;
        left = right = nullptr;
    }
};

class InventoryTree {
private:
    ProductNode* root;

    ProductNode* add(ProductNode* node, int id, int qty) {
        if (node == nullptr)
            return new ProductNode(id, qty);

        if (id < node->id)
            node->left = add(node->left, id, qty);
        else if (id > node->id)
            node->right = add(node->right, id, qty);
        else
            node->qty += qty;

        return node;
    }

    ProductNode* find(ProductNode* node, int id) {
        if (!node || node->id == id)
            return node;
        return (id < node->id) ? find(node->left, id) : find(node->right, id);
    }

    void displayInorder(ProductNode* node) {
        if (!node) return;
        displayInorder(node->left);
        cout<<"Product ID: "<<node->id 
            <<" | Quantity: "<<node->qty<<endl;
        displayInorder(node->right);
    }

    void maxQty(ProductNode* node, int &maxQ, int &maxId) {
        if (!node) return;
        if (node->qty > maxQ) {
            maxQ = node->qty;
            maxId = node->id;
        }
        maxQty(node->left, maxQ, maxId);
        maxQty(node->right, maxQ, maxId);
    }

public:
    InventoryTree() { root = nullptr; }

    void insertProduct(int id, int qty) {
        root = add(root, id, qty);
    }

    void searchProduct(int id) {
        ProductNode* res = find(root, id);
        if (res)
            cout<<"Product Found | ID: "<<res->id 
                <<" | Quantity: "<<res->qty<<endl;
        else
            cout<<"Product not found.\n";
    }

    void showAll() {
        if (!root)
            cout<<"No products available.\n";
        else {
            cout<<"\nProduct List:\n";
            displayInorder(root);
        }
    }

    void showMaxQuantity() {
        int maxQ = -1, maxId = -1;
        maxQty(root, maxQ, maxId);
        if (maxId != -1)
            cout<<"Product with Highest Quantity -> ID: " 
                <<maxId<<", Quantity: "<<maxQ<<endl;
        else
            cout<<"No products in inventory.\n";
    }
};

int main() {
    InventoryTree inv;
    int option, id, qty;

    while (true) {
        cout<<"\n--- Warehouse Inventory Menu ---\n";
        cout<<"1. Add or Update Product\n";
        cout<<"2. Search Product\n";
        cout<<"3. Display All Products\n";
        cout<<"4. Show Product with Highest Quantity\n";
        cout<<"5. Exit\n";
        cout<<"Enter your choice: ";
        cin>>option;

        switch (option) {
            case 1:
                cout<<"Enter Product ID and Quantity: ";
                cin>>id>>qty;
                inv.insertProduct(id, qty);
                break;

            case 2:
                cout<<"Enter Product ID to Search: ";
                cin>>id;
                inv.searchProduct(id);
                break;

            case 3:
                inv.showAll();
                break;

            case 4:
                inv.showMaxQuantity();
                break;

            case 5:
                cout<<"Exiting program...\n";
                return 0;

            default:
                cout<<"Invalid option! Try again.\n";
        }
    }
}
