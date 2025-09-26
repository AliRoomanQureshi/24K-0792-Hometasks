#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int bubbleSort(int arr[], int n) {
    int comps = 0;
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            comps++;
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
    return comps;
}

int insertionSort(int arr[], int n) {
    int comps = 0;
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0) {
            comps++;
            if (arr[j] > key) {
                arr[j+1] = arr[j];
                j--;
            } else {
                break;
            }
        }
        arr[j+1] = key;
    }
    return comps;
}

int selectionSort(int arr[], int n) {
    int comps = 0;
    for (int i = 0; i < n-1; i++) {
        int minIdx = i;
        for (int j = i+1; j < n; j++) {
            comps++;
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        swap(arr[minIdx], arr[i]);
    }
    return comps;
}

int shellSort(int arr[], int n) {
    int comps = 0;
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j = i;
            while (j >= gap) {
                comps++;
                if (arr[j - gap] > temp) {
                    arr[j] = arr[j - gap];
                    j -= gap;
                } else {
                    break;
                }
            }
            arr[j] = temp;
        }
    }
    return comps;
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void copyArray(int src[], int dest[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
    }
}

int main() {
    srand(time(0));

    int n1 = 20;
    int arr1[20];
    for (int i = 0; i < n1; i++) {
        arr1[i] = rand() % 100 + 1;
    }

    cout<<"Original Array (20 elements):\n";
    printArray(arr1, n1);
    cout<<endl;

    int temp[100];

    copyArray(arr1, temp, n1);
    cout<<"Bubble Sort:\n";
    int c1 = bubbleSort(temp, n1);
    printArray(temp, n1);
    cout<<"Comparisons: "<<c1<<"\n\n";

    copyArray(arr1, temp, n1);
    cout<<"Insertion Sort:\n";
    int c2 = insertionSort(temp, n1);
    printArray(temp, n1);
    cout<<"Comparisons: "<<c2<<"\n\n";

    copyArray(arr1, temp, n1);
    cout<<"Selection Sort:\n";
    int c3 = selectionSort(temp, n1);
    printArray(temp, n1);
    cout<<"Comparisons: "<<c3<<"\n\n";

    copyArray(arr1, temp, n1);
    cout<<"Shell Sort:\n";
    int c4 = shellSort(temp, n1);
    printArray(temp, n1);
    cout<<"Comparisons: "<<c4<<"\n\n";

    int n2 = 100;
    int arr2[100];
    for (int i = 0; i < n2; i++) {
        arr2[i] = rand() % 100 + 1;
    }
    cout<<"\nOriginal Array (100 elements):\n";
    printArray(arr2, n2);
    cout<<endl;
    copyArray(arr2, temp, n2);
    cout<<"Bubble Sort:\n";
    int c5 = bubbleSort(temp, n2);
    printArray(temp, n2);
    cout<<"Comparisons: "<<c5<<"\n\n";
    copyArray(arr2, temp, n2);
    cout<<"Insertion Sort:\n";
    int c6 = insertionSort(temp, n2);
    printArray(temp, n2);
    cout<<"Comparisons: "<<c6<<"\n\n";
    copyArray(arr2, temp, n2);
    cout<<"Selection Sort:\n";
    int c7 = selectionSort(temp, n2);
    printArray(temp, n2);
    cout<<"Comparisons: "<<c7<<"\n\n";
    copyArray(arr2, temp, n2);
    cout<<"Shell Sort:\n";
    int c8 = shellSort(temp, n2);
    printArray(temp, n2);
    cout<<"Comparisons: "<<c8<<"\n\n";
    return 0;
}
