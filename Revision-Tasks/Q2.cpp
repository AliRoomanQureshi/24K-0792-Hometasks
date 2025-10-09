#include <iostream>
#include <string>

using namespace std;

//answer1 Shell sort is faster than bubble sort because it reduces the total number of swaps and comparisons using gaps.
//Shell sort becomes faster when half the array is already sorted because fewer shifts are needed during the smaller gap passes.
void print(int *arr, int n){
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
ShellSort(int *arr, int n){
    for(int gap = n/2; gap >0;gap = gap/2){
        for(int j=gap; j<n; j++){
            int temp = arr[j];
            int res = j;
            while(res >= gap && arr[res-gap]>temp) {
                arr[res] = arr[res-gap];
                res = res-gap;
            }
            arr[res] = temp;
        }
    }
}
int main() {
    int arr[] = {32, 25, 40, 12, 18, 50, 28};
    int n = sizeof(arr) / sizeof(arr[0]);

    ShellSort(arr, n);

    cout<<endl;
    cout << "Sorted array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
