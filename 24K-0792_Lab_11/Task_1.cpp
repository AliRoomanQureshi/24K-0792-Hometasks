#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string data;
    Node* next;

    Node(string d) {
        data = d;
        next = NULL;
    }
};

class HashTable {
private:
    static const int SIZE = 10;
    Node* table[SIZE];

public:
    HashTable() {
        for (int i=0;i<SIZE;i++)
            table[i] = NULL;
    }

    int hashFunction(string s) {
        int sum = 0;
        for (char c : s)
            sum += int(c);
        return sum % SIZE;
    }

    void insert(string s) {
        int index = hashFunction(s);
        Node* newNode = new Node(s);

        newNode->next = table[index];
        table[index] = newNode;
    }

    bool search(string s) {
        int index = hashFunction(s);
        Node* temp = table[index];

        while (temp != NULL) {
            if (temp->data == s)
                return true;
            temp = temp->next;
        }
        return false;
    }

    void display() {
        cout<<"Hash Table:\n";
        for (int i = 0; i < SIZE; i++) {
            cout<<"Bucket "<<i<<": ";
            Node* temp = table[i];

            if (temp == NULL) {
                cout<<"NULL\n";
                continue;
            }

            while (temp != NULL) {
                cout<<temp->data<<" -> ";
                temp = temp->next;
            }
            cout<<"NULL\n";
        }
    }
};

int main() {
    HashTable ht;

    ht.insert("apple");
    ht.insert("mango");
    ht.insert("apple");   
    ht.insert("grapes");
    ht.insert("peach");
    ht.insert("banana");

    ht.display();

    cout<<"\nSearching 'apple' : ";
    if (ht.search("apple"))
        cout<<"Found\n";
    else
        cout<<"Not Found\n";

    cout<<"Searching 'orange' : ";
    if (ht.search("orange"))
        cout<<"Found\n";
    else
        cout<<"Not Found\n";

    return 0;
}
