#include <iostream>
using namespace std;

#define MAX 5
int cq[MAX], front = -1, rear = -1;

bool isEmpty() {
    return front == -1;
}

bool isFull() {
    return (rear + 1) % MAX == front;
}

void enqueue(int x) {
    if (isFull()) {
        cout << "Circular Queue is full\n";
    } else {
        if (front == -1) front = 0;
        rear = (rear + 1) % MAX;
        cq[rear] = x;
        cout << "Inserted: " << x << endl;
    }
}

void dequeue() {
    if (isEmpty()) {
        cout << "Circular Queue is empty\n";
    } else {
        cout << "Removed: " << cq[front] << endl;
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % MAX;
    }
}

void peek() {
    if (isEmpty())
        cout << "Circular Queue is empty\n";
    else
        cout << "Front element: " << cq[front] << endl;
}

void display() {
    if (isEmpty()) {
        cout << "Circular Queue is empty\n";
    } else {
        int i = front;
        while (true) {
            cout << cq[i] << " ";
            if (i == rear) break;
            i = (i + 1) % MAX;
        }
        cout << endl;
    }
}

int main() {
    int choice, value;
    do {
        cout << "\n1.Enqueue 2.Dequeue 3.Peek 4.Display 5.Exit\nChoice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
        }
    } while (choice != 5);
    return 0;
}
