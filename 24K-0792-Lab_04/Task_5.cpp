#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int main() {
    int n;
    cout<<"Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout<<"Enter "<<n<<" elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    bubbleSort(arr, n);
    cout<<"\nSorted Array: ";
    displayArray(arr, n);
    int key;
    cout<<"Enter element to search: ";
    cin >> key;
    int index = binarySearch(arr, n, key);
    if (index != -1)
        cout<<"Element "<<key<<" found at index "<<index<<endl;
    else
        cout<<"Element "<<key<<" not found!"<<endl;
    return 0;
}
