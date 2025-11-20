#include <iostream>
using namespace std;

class MinHeap {
private:
    int heap[100];
    int size;
public:
    MinHeap() {
        size=0;
    }
    void insert(int price) {
        size++;
        heap[size]=price;
        int i=size;
        while(i>1 && heap[i]<heap[i/2]) {
            int temp=heap[i];
            heap[i]=heap[i/2];
            heap[i/2]=temp;
            i=i/2;
        }
    }
    void removeMin() {
        if(size==0) return;
        heap[1]=heap[size];
        size--;
        int i=1;
        while(true) {
            int left=2*i;
            int right=2*i+1;
            int smallest=i;
            if(left<=size && heap[left]<heap[smallest])
                smallest=left;
            if(right<=size && heap[right]<heap[smallest])
                smallest=right;
            if(smallest!=i) {
                int temp=heap[i];
                heap[i]=heap[smallest];
                heap[smallest]=temp;
                i=smallest;
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
    MinHeap h;

    h.insert(100);
    h.insert(50);
    h.insert(75);
    h.insert(60);

    cout<<"Heap after inserting orders [100, 50, 75, 60]:"<<endl;
    h.display();

    h.insert(55);
    cout<<"Heap after inserting new order 55:"<<endl;
    h.display();

    h.removeMin();
    cout<<"Heap after executing order with highest priority (lowest price):"<<endl;
    h.display();

    return 0;
}
