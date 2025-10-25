#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string url;
    Node* next;
    Node(string u) {
        url = u;
        next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;
    LinkedList() { head = nullptr; }

    void addFront(string url) {
        Node* newNode = new Node(url);
        newNode->next = head;
        head = newNode;
    }

    void removeFront() {
        if (head == nullptr) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void display() {
        Node* temp = head;
        cout<<"Current Browsing History (Most Recent First):\n";
        while (temp != nullptr) {
            cout<<temp->url<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};

class Stack {
private:
    string arr[100];
    int topIndex;
public:
    Stack() { topIndex = -1; }
    bool empty() { return topIndex == -1; }
    void push(string url) { arr[++topIndex] = url; }
    string pop() { 
        if (empty()) return "";
        return arr[topIndex--];
    }
    string top() { 
        if (empty()) return "";
        return arr[topIndex];
    }
};

void goBack(LinkedList &list, Stack &stack, int steps) {
    cout<<"\nUser clicks 'Back' "<<steps<<" times...\n";
    for (int i = 0; i < steps; i++) {
        if (!stack.empty()) stack.pop();
        list.removeFront();
    }
    cout<<"Now viewing: "<<list.head->url<<endl;
}

int main() {
    LinkedList history;
    Stack backStack;

    history.addFront("Instagram");
    backStack.push("Instagram");

    history.addFront("LinkedIn");
    backStack.push("LinkedIn");

    history.addFront("Twitter");
    backStack.push("Twitter");

    history.addFront("Facebook");
    backStack.push("Facebook");

    history.addFront("Google");
    backStack.push("Google");

    cout<<"Initial Visit Order:\n";
    history.display();

    goBack(history, backStack, 2);

    cout<<"\nAfter going back twice:\n";
    history.display();

    return 0;
}
