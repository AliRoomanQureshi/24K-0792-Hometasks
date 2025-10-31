#include <iostream>
using namespace std;

int partitionFirst(int arr[], int low, int high, int& comps) {
    int pivot = arr[low];
    int i = low + 1;
    for (int j = low + 1; j <= high; j++) {
        comps++;
        if (arr[j] < pivot) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
        }
    }
    int temp = arr[low];
    arr[low] = arr[i - 1];
    arr[i - 1] = temp;
    return i - 1;
}

int partitionMiddle(int arr[], int low, int high, int& comps) {
    int mid = (low + high) / 2;
    int temp = arr[low];
    arr[low] = arr[mid];
    arr[mid] = temp;
    return partitionFirst(arr, low, high, comps);
}

int partitionRandom(int arr[], int low, int high, int& comps) {
    int seed = (low * 37 + high * 13 + 17) % (high - low + 1);
    int randIndex = low + seed;
    int temp = arr[low];
    arr[low] = arr[randIndex];
    arr[randIndex] = temp;
    return partitionFirst(arr, low, high, comps);
}

int partitionMedianOfThree(int arr[], int low, int high, int& comps) {
    int mid = (low + high) / 2;
    int a = arr[low], b = arr[mid], c = arr[high];
    int medianIndex;
    if ((a <= b && b <= c) || (c <= b && b <= a)) medianIndex = mid;
    else if ((b <= a && a <= c) || (c <= a && a <= b)) medianIndex = low;
    else medianIndex = high;
    int temp = arr[low];
    arr[low] = arr[medianIndex];
    arr[medianIndex] = temp;
    return partitionFirst(arr, low, high, comps);
}

void quickSort(int arr[], int low, int high, int& comps, int method) {
    if (low < high) {
        int p;
        if (method == 1) p = partitionFirst(arr, low, high, comps);
        else if (method == 2) p = partitionRandom(arr, low, high, comps);
        else if (method == 3) p = partitionMiddle(arr, low, high, comps);
        else p = partitionMedianOfThree(arr, low, high, comps);
        quickSort(arr, low, p - 1, comps, method);
        quickSort(arr, p + 1, high, comps, method);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) cout<<arr[i]<<" ";
    cout<<endl;
}

void copyArray(int src[], int dest[], int n) {
    for (int i = 0; i < n; i++) dest[i] = src[i];
}

int main() {
    int n;
    cout<<"Enter number of elements: ";
    cin >> n;

    int arr[100], temp[100];
    cout<<"Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    int comps;

    copyArray(arr, temp, n);
    comps = 0;
    quickSort(temp, 0, n - 1, comps, 1);
    cout<<"\nPivot: First Element\nComparisons: "<<comps<<"\nSorted: ";
    printArray(temp, n);

    copyArray(arr, temp, n);
    comps = 0;
    quickSort(temp, 0, n - 1, comps, 2);
    cout<<"\nPivot: Random Element\nComparisons: "<<comps<<"\nSorted: ";
    printArray(temp, n);

    copyArray(arr, temp, n);
    comps = 0;
    quickSort(temp, 0, n - 1, comps, 3);
    cout<<"\nPivot: Middle Element\nComparisons: "<<comps<<"\nSorted: ";
    printArray(temp, n);

    copyArray(arr, temp, n);
    comps = 0;
    quickSort(temp, 0, n - 1, comps, 4);
    cout<<"\nPivot: Median of Three\nComparisons: "<<comps<<"\nSorted: ";
    printArray(temp, n);

    cout<<"\nPress any key to continue . . . ";
    cin.ignore();
    cin.get();
    return 0;
}
