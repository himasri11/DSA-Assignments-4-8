#include <iostream>
using namespace std;

#define MAX 5
int queue[MAX], front = -1, rear = -1;

bool isEmpty() {
    return front == -1;
}

bool isFull() {
    return rear == MAX - 1;
}

void enqueue(int x) {
    if (isFull()) {
        cout << "Queue is full\n";
    } else {
        if (front == -1) front = 0;
        queue[++rear] = x;
        cout << "Inserted: " << x << endl;
    }
}

void dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty\n";
    } else {
        cout << "Removed: " << queue[front] << endl;
        if (front == rear)
            front = rear = -1;
        else
            front++;
    }
}

void peek() {
    if (isEmpty())
        cout << "Queue is empty\n";
    else
        cout << "Front element: " << queue[front] << endl;
}

void display() {
    if (isEmpty()) {
        cout << "Queue is empty\n";
    } else {
        for (int i = front; i <= rear; i++)
            cout << queue[i] << " ";
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
