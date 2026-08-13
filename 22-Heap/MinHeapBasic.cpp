#include <iostream>
#include <queue>
using namespace std;

int main() {
    priority_queue<int, vector<int>, greater<int>> minHeap; // Min Heap

    // Insert elements into the min heap
    minHeap.push(10);
    minHeap.push(20);
    minHeap.push(5);
    minHeap.push(15);

    cout << "Min Heap elements (in order of removal):" << endl;
    while(!minHeap.empty()){
        cout << minHeap.top() << " "; // Get the minimum element
        minHeap.pop(); // Remove the minimum element
    }
    cout << endl;

    return 0;
}