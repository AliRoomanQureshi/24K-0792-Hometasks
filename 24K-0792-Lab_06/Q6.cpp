#include <iostream>
#include <string>
using namespace std;

#define MAX 100

struct Order {
    string itemName;
    int quantity;
};

class Queue {
private:
    Order orders[MAX];
    int front, rear;
public:
    Queue() {
        front = rear = -1;
    }

    bool isFull() {
        return rear == MAX - 1;
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }

    void enqueue(string name, int qty) {
        if (isFull()) {
            cout<<"Overflow! Cannot add more orders.\n";
            return;
        }
        if (front == -1) front = 0;
        rear++;
        orders[rear].itemName = name;
        orders[rear].quantity = qty;
        cout<<"Order added: "<<name<<" ("<<qty<<")\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout<<"Underflow! No orders to process.\n";
            return;
        }
        cout<<"Processing order: "<<orders[front].itemName 
            <<" ("<<orders[front].quantity<<")\n";
        front++;
    }

    void display() {
        if (isEmpty()) {
            cout<<"No pending orders.\n";
            return;
        }
        cout<<"\nPending Orders:\n";
        for (int i = front; i <= rear; i++) {
            cout<<orders[i].itemName<<" ("<<orders[i].quantity<<")\n";
        }
    }
};

int main() {
    Queue q;
    q.enqueue("Burger", 2);
    q.enqueue("Pizza", 1);
    q.enqueue("Pasta", 3);
    q.display();

    q.dequeue();
    q.dequeue();
    q.display();
    return 0;
}
