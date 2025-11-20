#include <iostream>
using namespace std;

class MinHeap {
private:
    int heap[100];
    int size;

public:
    MinHeap() {
        size = 0;
    }

    void insert(int priority) {
        size++;
        heap[size] = priority;

        int i = size;
        while (i>1 && heap[i]<heap[i/2]){
            int temp = heap[i];
            heap[i] = heap[i/2];
            heap[i/2] = temp;
            i = i/2;
        }
    }

    void display() {
        for (int i=1; i<=size; i++) {
            cout<<heap[i]<< " ";
        }
        cout<<endl;
    }
};

int main() {
    MinHeap h;

    h.insert(1);
    h.insert(3);
    h.insert(4);
    h.insert(5);
    h.insert(6);

    h.display();

    h.insert(2);

    h.display();

    return 0;
}

