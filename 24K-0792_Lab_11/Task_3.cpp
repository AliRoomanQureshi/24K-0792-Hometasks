#include <iostream>
using namespace std;

class Hash {
private:
    int arr[10];
    int size;

public:
    Hash() {
        size = 10;
        for (int i = 0; i < size; i++)
            arr[i] = -1; 
    }

    void insert(int value) {
        int index = value % size;

        while (arr[index] != -1) {
            index = (index + 1) % size;
        }
        arr[index] = value;
    }

    void remove(int value) {
        int index = value % size;
        int start = index;

        while (arr[index] != -1) {
            if (arr[index] == value) {
                arr[index] = -1;
                return;
            }
            index = (index + 1) % size;

            if (index == start) break;
        }
    }

    bool search(int value) {
        int index = value % size;
        int start = index;

        while (arr[index] != -1) {
            if (arr[index] == value)
                return true;
            index = (index + 1) % size;

            if (index == start) break;
        }
        return false;
    }

    void display() {
        for (int i = 0; i < size; i++) {
            if (arr[i] != -1)
                cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};


int main() {
    Hash h;

    h.insert(1);
    h.insert(3);
    h.insert(4);
    h.insert(5);
    h.insert(7);

    h.display();       
    
    cout<<"Remove 4"<<endl;
    h.remove(4);

    h.display();       

    if (h.search(5))
        cout<<"5 found"<<endl;
    else
        cout<<"5 not found"<<endl;

    if (h.search(6))
        cout<<"6 found"<<endl;
    else
        cout<<"6 not found"<<endl;

    return 0;
}
