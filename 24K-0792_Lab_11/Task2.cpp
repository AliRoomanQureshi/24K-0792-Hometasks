#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string word;
    Node* next;

    Node(string w) {
        word = w;
        next = NULL;
    }
};

class Dictionary {
private:
    static const int SIZE = 100;
    Node* table[SIZE];

public:
    Dictionary() {
        for (int i = 0; i < SIZE; i++)
            table[i] = NULL;
    }

    int hashFunction(string w) {
        int sum = 0;
        for (char c : w)
            sum += int(c);
        return sum % SIZE;
    }

    void Add_Record(string w) {
        int index = hashFunction(w);
        Node* newNode = new Node(w);

        newNode->next = table[index];
        table[index] = newNode;

        cout<<"Record added successfully!\n";
    }

    void Word_Search(string w) {
        int index = hashFunction(w);
        Node* temp = table[index];

        while (temp != NULL) {
            if (temp->word == w) {
                cout<<"Word '"<<w<<"' found in dictionary.\n";
                return;
            }
            temp = temp->next;
        }

        cout<<"Error: Word '"<<w<<"' NOT found in dictionary.\n";
    }
    void Print_Dictionary() {
        cout<<"\n----- Complete Dictionary -----\n";
        for (int i = 0; i < SIZE; i++) {
            cout<<"Bucket "<<i<<": ";
            Node* temp = table[i];
            if (temp == NULL) {
                cout<<"NULL\n";
                continue;
            }

            while (temp != NULL) {
                cout<<temp->word<<" -> ";
                temp = temp->next;
            }
            cout<<"NULL\n";
        }
        cout<<"-------------------------------\n";
    }
};

int main() {
    Dictionary dict;
    int choice;
    string word;

    while (true) {
        cout<<"\n===== ASCII Dictionary Menu =====\n";
        cout<<"1. Add Record\n";
        cout<<"2. Search Word\n";
        cout<<"3. Print Dictionary\n";
        cout<<"4. Exit\n";
        cout<<"Enter choice: ";
        cin>>choice;

        switch (choice) {
        case 1:
            cout<<"Enter word to add: ";
            cin>>word;
            dict.Add_Record(word);
            break;

        case 2:
            cout<<"Enter word to search: ";
            cin>>word;
            dict.Word_Search(word);
            break;

        case 3:
            dict.Print_Dictionary();
            break;

        case 4:
            cout<<"Exiting program...\n";
            return 0;

        default:
            cout<<"Invalid choice. Try again.\n";
        }
    }

    return 0;
}
