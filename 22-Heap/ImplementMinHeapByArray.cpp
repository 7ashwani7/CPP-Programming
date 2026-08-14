#include <iostream>
using namespace std;

class MinHeap {
    int arr[100];
    int size;

public:
    MinHeap() {
        size = 0;
    }
    // Insert element
    void push(int val) {
        arr[size] = val;
        int i = size;
        size++;
        while(i > 0){
            int parent = (i - 1) / 2;
            if(arr[parent] <= arr[i]) break;
            swap(arr[parent], arr[i]);
            i = parent;
        }
    }
    // Return minimum element
    int top(){
        if(size == 0){
            cout << "Heap is Empty\n";
            return -1;
        }
        return arr[0];
    }
    // Remove minimum element
    void pop() {
        if(size == 0){
            cout << "Heap is Empty\n";
            return;
        }
        arr[0] = arr[size - 1];
        size--;
        int i = 0;
        while(true){
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int smallest = i;
            if(left < size && arr[left] < arr[smallest]) smallest = left;
            if(right < size && arr[right] < arr[smallest]) smallest = right;
            if(smallest == i) break;
            swap(arr[i], arr[smallest]);
            i = smallest;
        }
    }
    // Print heap
    void print() {
        for(int i = 0; i < size; i++) cout << arr[i] << " ";
        cout << endl;
    }
};
int main() {
    MinHeap pq;

    pq.push(10);
    pq.push(5);
    pq.push(20);
    pq.push(2);
    pq.push(15);

    cout << "Heap: ";
    pq.print();

    cout << "Top Element: " << pq.top() << endl;

    pq.pop();

    cout << "After Pop: ";
    pq.print();

    cout << "Top Element: " << pq.top() << endl;

    return 0;
}