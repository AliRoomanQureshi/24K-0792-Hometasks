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
			int m = getMax(arr, n);
			for (int exp = 1; m / exp > 0; exp *= 10)
				countingSort(arr, n, exp);
		}
};

int main() {
	int n;
	cout<<"Enter number of transactions: ";
	cin >> n;

	int transactions[100];
	cout<<"Enter transaction amounts:\n";
	for (int i = 0; i < n; i++)
		cin >> transactions[i];

	RadixSort sorter;
	sorter.sort(transactions, n);

	cout<<"\nSorted Transaction Amounts (Ascending): ";
	for (int i = 0; i < n; i++)
		cout<<transactions[i]<<" ";

	cout<<endl;
	return 0;
}
