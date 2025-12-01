
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node *prev;

    Node(int x) {
        data = x;
        next = nullptr;
        prev = nullptr;
    }
};

Node *reverseKNodes(Node *head, int k) {
    Node *curr = head, *prev = nullptr, *next = nullptr;
    int count = 0;

    while (curr != nullptr && count < k) {
        next = curr->next;
        curr->next = prev;
        curr->prev = nullptr;
        if (prev != nullptr) {
            prev->prev = curr;
        }
        prev = curr;
        curr = next;
        count++;
    }

    return prev;
}

Node *reverseKGroup(Node *head, int k) {
    if (head == nullptr) {
        return head;
    }
    Node *groupHead = nullptr;
    Node *newHead = nullptr;

    Node *temp = head;
    int count = 0;
    while (temp && count < k) {
        temp = temp->next;
        count++;
    }
    groupHead = reverseKNodes(head, k);

    if (newHead == nullptr) {
        newHead = groupHead;
    }

    head->next = reverseKGroup(temp, k);
    if (head->next != nullptr) {
        head->next->prev = head;
    }

    return newHead;
}

void printList(Node *head) {
    Node *curr = head;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
  
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(4);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->prev = head->next->next->next;
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->prev = head->next->next->next->next;

    head = reverseKGroup(head, 2);
    printList(head);

    return 0;
}