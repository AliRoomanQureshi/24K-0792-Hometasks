#include <iostream>
#include <cstring>
using namespace std;

struct Participant {
    char name[50];
    int time;  
};

void merge(Participant arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Participant L[20];
    Participant R[20];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i].time <= R[j].time) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) {
        arr[k++] = L[i++];
    }

    while (j < n2) {
        arr[k++] = R[j++];
    }
}

void mergeSort(Participant arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    Participant runners[10] = {
        {"Ahmed", 3723},
        {"Bilal", 3650},
        {"Sara", 3580},
        {"Zain", 4000},
        {"Aisha", 3490},
        {"Omar", 3895},
        {"Hira", 3555},
        {"Fahad", 3420},
        {"Nadia", 3700},
        {"Kamran", 3600}
    };

    int n = 10;

    cout << "Original list:\n";
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". " << runners[i].name << "  " << runners[i].time << " seconds\n";
    }

    mergeSort(runners, 0, n - 1);

    cout << "\nSorted list (ascending by finish time):\n";
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". " << runners[i].name << "  " << runners[i].time << " seconds\n";
    }

    cout << "\nTop 5 fastest runners:\n";
    for (int i = 0; i < 5; i++) {
        cout << i + 1 << ". " << runners[i].name << "  " << runners[i].time << " seconds\n";
    }

    return 0;
}
