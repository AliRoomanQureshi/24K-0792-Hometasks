#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;

class Call {
public:
    string name;
    string number;
    int duration;

    Call() {}
    Call(string n, string num, int d) {
        name = n;
        number = num;
        duration = d;
    }

    void display() {
        cout<<"Name: "<<name<<", Number: "<<number 
            <<", Duration: "<<duration<<" mins"<<endl;
    }
};

class CallStack {
private:
    Call stack[MAX];
    int topIndex;

public:
    CallStack() {
        topIndex = -1;
    }

    bool empty() {
        return topIndex == -1;
    }

    bool full() {
        return topIndex == MAX - 1;
    }

    void push(Call c) {
        if (full()) {
            cout<<"Call history is full!\n";
            return;
        }
        stack[++topIndex] = c;
        cout<<"Call added successfully.\n";
        display();
    }

    void pop() {
        if (empty()) {
            cout<<"No calls to delete!\n";
            return;
        }
        cout<<"Deleting most recent call: ";
        stack[topIndex--].display();
        display();
    }

    void top() {
        if (empty()) {
            cout<<"No recent call to show!\n";
            return;
        }
        cout<<"Most recent call:\n";
        stack[topIndex].display();
    }

    void display() {
        if (empty()) {
            cout<<"Call history is empty.\n";
            return;
        }
        cout<<"\nCurrent Call Log:\n";
        for (int i = topIndex; i >= 0; i--) {
            cout<<topIndex - i + 1<<". ";
            stack[i].display();
        }
        cout<<endl;
    }
};

int main() {
    CallStack history;
    int choice;

    do {
        cout<<"\n===== Mobile Call History =====\n";
        cout<<"1. Add New Call (Push)\n";
        cout<<"2. Delete Most Recent Call (Pop)\n";
        cout<<"3. View Most Recent Call (Top)\n";
        cout<<"4. Check if Call History is Empty\n";
        cout<<"5. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;
        cin.ignore();

        if (choice == 1) {
            string name, number;
            int duration;
            cout<<"Enter Name: ";
            getline(cin, name);
            cout<<"Enter Number: ";
            getline(cin, number);
            cout<<"Enter Duration (in minutes): ";
            cin >> duration;
            Call c(name, number, duration);
            history.push(c);
        } 
        else if (choice == 2) {
            history.pop();
        } 
        else if (choice == 3) {
            history.top();
        } 
        else if (choice == 4) {
            if (history.empty())
                cout<<"Yes, call history is empty.\n";
            else
                cout<<"No, call history is not empty.\n";
        } 
        else if (choice != 5) {
            cout<<"Invalid choice! Try again.\n";
        }
    } while (choice != 5);

    cout<<"Exiting program...\n";
    return 0;
}
