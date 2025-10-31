#include <iostream>
#include <string>
using namespace std;

class Order {
public:
    int orderID;
    string customerName;
    float totalPrice;
};

int partition(Order arr[], int low, int high) {
    float pivot = arr[high].totalPrice;
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j].totalPrice < pivot) {
            i++;
            Order temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    Order temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

void quickSort(Order arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void displayOrders(Order arr[], int n) {
    cout<<"\nSorted Orders (Ascending by Total Price):\n";
    cout<<"Order ID\tCustomer Name\tTotal Price\n";
    for (int i = 0; i < n; i++) {
        cout<<arr[i].orderID<<"\t\t"<<arr[i].customerName<<"\t\t"<<arr[i].totalPrice<<endl;
    }
}

int main() {
    int n;
    cout<<"Enter number of orders: ";
    cin >> n;

    Order orders[100];
    for (int i = 0; i < n; i++) {
        cout<<"\nEnter details for order "<<i + 1<<":\n";
        cout<<"Order ID: ";
        cin >> orders[i].orderID;
        cout<<"Customer Name: ";
        cin >> orders[i].customerName;
        cout<<"Total Price: ";
        cin >> orders[i].totalPrice;
    }

    quickSort(orders, 0, n - 1);
    displayOrders(orders, n);

    cout<<"\nPress any key to continue . . . ";
    cin.ignore();
    cin.get();
    return 0;
}
