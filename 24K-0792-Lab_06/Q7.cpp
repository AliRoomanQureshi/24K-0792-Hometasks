#include <iostream>
#include <string>
using namespace std;

#define MAX 100

class LibraryQueue {
private:
    string patrons[MAX];
    int front, rear;
public:
    LibraryQueue() {
        front = rear = -1;
    }

    bool isFull() {
        return rear == MAX - 1;
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }

    void addPatron(string name) {
        if (isFull()) {
            cout<<"Queue is full. Cannot add more patrons.\n";
            return;
        }
        if (front == -1) front = 0;
        patrons[++rear] = name;
        cout<<name<<" has joined the queue.\n";
    }

    void removePatron() {
        if (isEmpty()) {
            cout<<"Queue is empty. No patrons to service.\n";
            return;
        }
        cout<<patrons[front]<<" has completed their transaction and left the queue.\n";
        front++;
    }

    void displayQueue() {
        if (isEmpty()) {
            cout<<"No patrons in the queue.\n";
            return;
        }
        cout<<"\nCurrent Queue:\n";
        for (int i = front; i <= rear; i++) {
            cout<<i - front + 1<<". "<<patrons[i]<<endl;
        }
    }
};
int main() {
    LibraryQueue queue;
    int choice;
    string name;

    do {
        cout<<"\n--- Library Queue System ---\n";
        cout<<"1. Add Patron\n";
        cout<<"2. Service Patron (Remove)\n";
        cout<<"3. Display Queue\n";
        cout<<"4. Exit\n";
        cout<<"Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout<<"Enter patron name: ";
                cin.ignore();
                getline(cin, name);
                queue.addPatron(name);
                break;
            case 2:
                queue.removePatron();
                break;
            case 3:
                queue.displayQueue();
                break;
            case 4:
                cout<<"Exiting program...\n";
                break;
            default:
                cout<<"Invalid choice.\n";
        }
    } while (choice != 4);
    return 0;
}
