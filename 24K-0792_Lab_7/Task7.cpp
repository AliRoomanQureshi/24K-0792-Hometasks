#include <iostream>
using namespace std;

int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

void countingSort(int arr[], int n, int exp) {
    int output[50];
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

void radixSort(int arr[], int n) {
    int max = getMax(arr, n);

    for (int exp = 1; max / exp > 0; exp *= 10)
        countingSort(arr, n, exp);
}

void displayRanks(int arr[], int n) {
    cout << "\nStudent\tScore\tRank\n";
    cout << "----------------------\n";
    for (int i = 0; i < n; i++) {
        cout << i + 1 << "\t" << arr[i] << "\t" << i + 1 << endl;
    }
}

int main() {
    int scores[50] = {
        67, 89, 45, 90, 12, 77, 56, 88, 99, 23,
        54, 43, 22, 67, 78, 45, 88, 55, 66, 99,
        12, 10, 34, 65, 88, 23, 44, 56, 89, 90,
        99, 40, 33, 28, 50, 60, 70, 80, 90, 100,
        5, 15, 25, 35, 45, 55, 65, 75, 85, 95
    };

    int n = 50;

    cout << "Original Scores:\n";
    for (int i = 0; i < n; i++)
        cout << scores[i] << " ";
    cout << endl;

    radixSort(scores, n);

    cout << "\nSorted Scores (Ascending Order):\n";
    for (int i = 0; i < n; i++)
        cout << scores[i] << " ";

    cout << endl;
    displayRanks(scores, n);

    return 0;
}
