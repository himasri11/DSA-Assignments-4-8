#include <iostream>
using namespace std;

class Node {
public:
    char data;
    Node* next;
    Node* prev;
    Node(char c) {
        data = c;
        next = prev = NULL;
    }
};

int main() {
    Node *head = NULL, *tail = NULL;
    int n;
    char ch;

    cout << "Enter number of characters: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter character " << i + 1 << ": ";
        cin >> ch;

        Node* newNode = new Node(ch);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    
    cout << "Doubly Linked List: ";
    Node* temp = head;
    while (temp) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL\n";

    
    Node* left = head;
    Node* right = tail;
    bool isPal = true;

    while (left != right && right->next != left) {
        if (left->data != right->data) {
            isPal = false;
            break;
        }
        left = left->next;
        right = right->prev;
    }

    if (isPal)
        cout << "The Doubly Linked List is a PALINDROME" << endl;
    else
        cout << "The Doubly Linked List is NOT a palindrome" << endl;

    return 0;
}
