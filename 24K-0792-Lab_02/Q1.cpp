#include <iostream>
using namespace std;

class DynamicArr {
private:
    int* data;
    int size;
    int capacity;

    void resize() {
        int newCapacity = (capacity == 0) ? 1 : capacity * 2;
        int* newData = new int[newCapacity];
        
        for (int i = 0; i < size; i++) {
            newData[i] = data[i];
        }
        
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

public:
    DynamicArr(int initialCapacity = 2) {
        capacity = initialCapacity;
        size = 0;
        data = new int[capacity];
    }

    ~DynamicArr() {
        delete[] data;
    }

    DynamicArr(const DynamicArr& other) {
        capacity = other.capacity;
        size = other.size;
        data = new int[capacity];
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }

    DynamicArr& operator=(const DynamicArr& other) {
        if (this != &other) {
            delete[] data;
            capacity = other.capacity;
            size = other.size;
            data = new int[capacity];
            for (int i = 0; i < size; i++) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    void push_back(int value) {
        if (size >= capacity) {
            resize();
        }
        
        data[size] = value;
        size++;
    }

    void print() const {
        for (int i = 0; i < size; i++) {
            cout << data[i];
            if (i < size - 1) {
                cout << ", ";
            }
        }
        cout << endl;
    }

    int getSize() const {
        return size;
    }

    int getCapacity() const {
        return capacity;
    }

    int at(int index) const {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of bounds");
        }
        return data[index];
    }

    int& operator[](int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of bounds");
        }
        return data[index];
    }

    const int& operator[](int index) const {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of bounds");
        }
        return data[index];
    }
};

int main() {
    DynamicArr arr(2);
    
    arr.push_back(10);
    arr.push_back(20);
    arr.push_back(30);
    arr.push_back(40);
    arr.push_back(50);

    arr.print();
    
    cout<<"Element at index 0: "<<arr[0]<<endl;
    cout<<"Element at index 2: "<<arr[2]<<endl;
    
    cout<<"Size: "<<arr.getSize()<<endl;
    cout<<"Capacity: "<<arr.getCapacity()<<endl;
    arr.push_back(60);
    arr.push_back(70);
    arr.push_back(80);
    arr.print();
    cout<<"Final size: "<<arr.getSize()<<endl;
    cout<<"Final capacity: "<<arr.getCapacity()<<endl;
    return 0;
}