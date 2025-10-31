#include <iostream>
using namespace std;

class RadixSort {
private:
    int getMax(int arr[], int n) {
        int max = arr[0];
        for (int i = 1; i < n; i++)
            if (arr[i] > max)
                max = arr[i];
        return max;
    }
    void countingSort(int arr[], int n, int exp) {
        int output[100]; 
        int count[10] = {0};

        for (int i = 0; i < n; i++)
            count[(arr[i] / exp) % 10]++;

        for (int i = 1; i < 10; i++)
            count[i] += count[i - 1];

        for (int i = n - 1; i >= 0; i--) {
            int digit = (arr[i] / exp) % 10;
            output[count[digit] - 1] = arr[i];
            count[digit]--;
        }

        for (int i = 0; i < n; i++)
            arr[i] = output[i];
    }

public:
    void sort(int arr[], int n) {
        int max = getMax(arr, n);
        int pass = 1;

        cout<<"\nBefore Sorting: ";
        for (int i = 0; i < n; i++)
            cout<<arr[i]<<" ";

        for (int exp = 1; max / exp > 0; exp *= 10) {
            countingSort(arr, n, exp);

            cout<<"\nAfter Pass "<<pass<<" (Sorting by " 
                <<exp<<"'s place): ";
            for (int i = 0; i < n; i++)
                cout<<arr[i]<<" ";
            pass++;
        }
    }
};

int main() {
    const int n = 20;
    int productIDs[n];

    cout<<"Enter 20 product IDs (each 5-digit integer):\n";
    for (int i = 0; i < n; i++)
        cin >> productIDs[i];

    RadixSort sorter;
    sorter.sort(productIDs, n);

    cout<<"\n\nFinal Sorted Product IDs (Ascending): ";
    for (int i = 0; i < n; i++)
        cout<<productIDs[i]<<" ";

    cout<<endl;
    return 0;
}
