#include <iostream>
using namespace std;

struct Task {
    char name;
    int priority;
};

class MaxHeap {
private:
    Task heap[100];
    int size;
public:
    MaxHeap() {
        size=0;
    }
    void insert(Task t) {
        size++;
        heap[size]=t;
        int i=size;
        while(i>1 && heap[i].priority>heap[i/2].priority) {
            Task temp=heap[i];
            heap[i]=heap[i/2];
            heap[i/2]=temp;
            i=i/2;
        }
    }
    void removeMax() {
        if(size==0) return;
        heap[1]=heap[size];
        size--;
        int i=1;
        while(true) {
            int left=2*i;
            int right=2*i+1;
            int largest=i;
            if(left<=size && heap[left].priority>heap[largest].priority)
                largest=left;
            if(right<=size && heap[right].priority>heap[largest].priority)
                largest=right;
            if(largest!=i) {
                Task temp=heap[i];
                heap[i]=heap[largest];
                heap[largest]=temp;
                i=largest;
            } else break;
        }
    }
    void display() {
        for(int i=1;i<=size;i++)
            cout<<heap[i].name<<"("<<heap[i].priority<<") ";
        cout<<endl;
    }
};

int main() {
    MaxHeap h;

    h.insert({'A',5});
    h.insert({'B',3});
    h.insert({'C',8});

    cout<<"Heap after inserting A(5), B(3), C(8):"<<endl;
    h.display();

    h.removeMax();
    cout<<"Heap after removing highest priority task:"<<endl;
    h.display();

    h.insert({'D',6});
    cout<<"Heap after inserting D(6):"<<endl;
    h.display();

    return 0;
}
