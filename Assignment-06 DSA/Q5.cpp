#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

int main() {
    Node *head = NULL, *temp = NULL, *newNode = NULL;
    int n, val;

    cout << "Enter number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> val;

        newNode = new Node(val);
        if (head == NULL) {
            head = temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    Node* ptr = head;
    bool isCircular = false;

    if (head != NULL) {
        ptr = head->next;
        while (ptr != NULL && ptr != head)
            ptr = ptr->next;
        if (ptr == head)
            isCircular = true;
    }

    if (isCircular)
        cout << "The Linked List is CIRCULAR" << endl;
    else
        cout << "The Linked List is NOT circular" << endl;

    return 0;
}
