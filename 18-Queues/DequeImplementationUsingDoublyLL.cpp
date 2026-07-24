#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = next = NULL;
    }
};

class Deque {
    Node* front;
    Node* rear;
    int cnt;

public:
    Deque() {
        front = rear = NULL;
        cnt = 0;
    }

    void addFront(int x) {
        Node* newNode = new Node(x);

        if (front == NULL) {
            front = rear = newNode;
        } else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }

        cnt++;
    }

    void addRear(int x) {
        Node* newNode = new Node(x);

        if (rear == NULL) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }

        cnt++;
    }

    void deleteFront() {
        if (front == NULL) {
            cout << "Deque Underflow\n";
            return;
        }

        Node* temp = front;
        front = front->next;

        if (front)
            front->prev = NULL;
        else
            rear = NULL;

        delete temp;
        cnt--;
    }

    void deleteRear() {
        if (rear == NULL) {
            cout << "Deque Underflow\n";
            return;
        }

        Node* temp = rear;
        rear = rear->prev;

        if (rear)
            rear->next = NULL;
        else
            front = NULL;

        delete temp;
        cnt--;
    }

    int getFront() {
        if (front == NULL)
            return -1;

        return front->data;
    }

    int getRear() {
        if (rear == NULL)
            return -1;

        return rear->data;
    }

    int size() {
        return cnt;
    }

    bool empty() {
        return cnt == 0;
    }

    void display() {
        Node* temp = front;

        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main() {
    Deque dq;

    dq.addFront(20);
    dq.addFront(10);
    dq.addRear(30);
    dq.addRear(40);

    cout << "Deque: ";
    dq.display();

    cout << "Front: " << dq.getFront() << endl;
    cout << "Rear: " << dq.getRear() << endl;
    cout << "Size: " << dq.size() << endl;

    dq.deleteFront();
    dq.deleteRear();

    cout << "After Deletions: ";
    dq.display();

    return 0;
}