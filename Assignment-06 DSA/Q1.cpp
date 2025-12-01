#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int d) {
        data = d;
        next = prev = NULL;
    }
};

class DoublyLinkedList {
    Node* head;

public:
    DoublyLinkedList() { head = NULL; }

   
    void insertAtBegin(int data) {
        Node* newNode = new Node(data);
        if (head == NULL)
            head = newNode;
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertAtEnd(int data) {
        Node* newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

    void insertAfter(int key, int data) {
        Node* temp = head;
        while (temp && temp->data != key)
            temp = temp->next;
        if (temp == NULL) {
            cout << "Node " << key << " not found.\n";
            return;
        }
        Node* newNode = new Node(data);
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next)
            temp->next->prev = newNode;
        temp->next = newNode;
        cout << "Inserted " << data << " after " << key << ".\n";
    }

    void insertBefore(int key, int data) {
        Node* temp = head;
        while (temp && temp->data != key)
            temp = temp->next;
        if (temp == NULL) {
            cout << "Node " << key << " not found.\n";
            return;
        }
        Node* newNode = new Node(data);
        newNode->next = temp;
        newNode->prev = temp->prev;
        if (temp->prev)
            temp->prev->next = newNode;
        else
            head = newNode;
        temp->prev = newNode;
        cout << "Inserted " << data << " before " << key << ".\n";
    }

   
    void deleteNode(int key) {
        Node* temp = head;
        while (temp && temp->data != key)
            temp = temp->next;
        if (temp == NULL) {
            cout << "Node " << key << " not found.\n";
            return;
        }
        if (temp->prev)
            temp->prev->next = temp->next;
        else
            head = temp->next;
        if (temp->next)
            temp->next->prev = temp->prev;
        delete temp;
        cout << "Node " << key << " deleted.\n";
    }

 
    bool search(int key) {
        Node* temp = head;
        while (temp) {
            if (temp->data == key) {
                cout << "Node " << key << " found.\n";
                return true;
            }
            temp = temp->next;
        }
        cout << "Node " << key << " not found.\n";
        return false;
    }

   
    void display() {
        Node* temp = head;
        if (!temp) {
            cout << "List is empty.\n";
            return;
        }
        cout << "Doubly Linked List: ";
        while (temp) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};



       
