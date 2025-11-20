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
    void insert(int rating) {
        size++;
        heap[size]=rating;
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

    h.insert(1500);
    h.insert(1200);
    h.insert(1800);
    h.insert(1600);

    cout<<"Current queue:"<<endl;
    h.display();

    h.insert(1700);
    cout<<"Queue after inserting player with rating 1700:"<<endl;
    h.display();

    h.removeMax();
    cout<<"Queue after matching player with highest rating:"<<endl;
    h.display();

    return 0;
}
