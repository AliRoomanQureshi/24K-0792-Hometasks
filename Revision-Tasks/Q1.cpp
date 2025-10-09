#include <iostream>
#include <string>

using namespace std;
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
       print(arr, n);
    }
}
int main() {
    int arr[] = {205, 102, 310, 450, 120, 90};
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
