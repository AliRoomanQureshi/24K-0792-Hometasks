#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    int price;
    Node* next;

    Node(string n, int p) {
        name = n;
        price = p;
        next = NULL;
    }
};

class ShoppingCart {
private:
    Node* head;

public:
    ShoppingCart() {
        head = NULL;
    }

    void addFront(string name, int price) {
        Node* newNode = new Node(name, price);
        newNode->next = head;
        head = newNode;
    }

    void addEnd(string name, int price) {
        Node* newNode = new Node(name, price);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void insertAfter(string target, string name, int price) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->name == target) {
                Node* newNode = new Node(name, price);
                newNode->next = temp->next;
                temp->next = newNode;
                return;
            }
            temp = temp->next;
        }
        cout<<"Item \""<<target<<"\" not found in the cart.\n";
    }

    void searchItem(string name) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->name == name) {
                cout<<name<<" found! Price: $"<<temp->price<<endl;
                return;
            }
            temp = temp->next;
        }
        cout<<name<<" not found in the cart.\n";
    }

    void displayCart() {
        Node* temp = head;
        cout<<"\nShopping Cart Items:\n";
        while (temp != NULL) {
            cout<<temp->name<<" $"<<temp->price<<endl;
            temp = temp->next;
        }
        cout<<endl;
    }
};

int main() {
    ShoppingCart cart;

    cart.addEnd("Laptop", 1000);
    cart.addEnd("Phone", 700);
    cart.addEnd("Tablet", 400);
    cart.addEnd("Headphones", 150);
    cart.addFront("Smartwatch", 200);          
    cart.addEnd("Keyboard", 80);          
    cart.insertAfter("Phone", "Monitor", 300); 
    cart.searchItem("Tablet");                 
    cart.displayCart();

    return 0;
}
