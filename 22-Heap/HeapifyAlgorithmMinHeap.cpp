#include <iostream>
using namespace std;

// Heapify a subtree rooted at index i
void heapify(int arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // Check left child
    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    // Check right child
    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    // If smallest is not the root
    if (smallest != i) {
        swap(arr[i], arr[smallest]);

        // Heapify the affected subtree
        heapify(arr, n, smallest);
    }
}

int main() {
    int arr[] = {8, 5, 7, 2, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Before Heapify: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    // Heapify from root
    heapify(arr, n, 0);

    cout << "After Heapify: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}