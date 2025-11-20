#include <iostream>
using namespace std;

class MaxHeap {
private:
    int heap[100];
    int size;
public:
    MaxHeap() {
        size=0;
    }
    void insert(int severity) {
        size++;
        heap[size]=severity;
        int i=size;
        while(i>1 && heap[i]>heap[i/2]) {
            int temp=heap[i];
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
            if(left<=size && heap[left]>heap[largest])
                largest=left;
            if(right<=size && heap[right]>heap[largest])
                largest=right;
            if(largest!=i) {
                int temp=heap[i];
                heap[i]=heap[largest];
                heap[largest]=temp;
                i=largest;
            } else break;
        }
    }
    void display() {
        for(int i=1;i<=size;i++)
            cout<<heap[i]<<" ";
        cout<<endl;
    }
};

int main() {
    MaxHeap h;
    h.insert(9);
    h.insert(7);
    h.insert(8);
    h.insert(3);
    h.insert(6);
    h.insert(5);
    cout<<"Heap before inserting 10:"<<endl;
    h.display();
    h.insert(10);
    cout<<"Heap after inserting 10:"<<endl;
    h.display();
    h.removeMax();
    cout<<"Heap after removing highest severity patient:"<<endl;
    h.display();
    return 0;
}
