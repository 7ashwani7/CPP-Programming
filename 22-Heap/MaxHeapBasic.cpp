#include <iostream>
#include <queue>
using namespace std;
int main() {
    priority_queue<int> maxHeap; // Max Heap

    // Insert elements into the max heap
    maxHeap.push(10);
    maxHeap.push(20);
    maxHeap.push(5);
    maxHeap.push(15);

    cout << "Max Heap elements (in order of removal):" << endl;
    while(!maxHeap.empty()){
        cout << maxHeap.top() << " "; // Get the maximum element
        maxHeap.pop(); // Remove the maximum element
    }
    cout << endl;

    return 0;
}