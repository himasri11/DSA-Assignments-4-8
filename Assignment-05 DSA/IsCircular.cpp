#include <iostream>
using namespace std;
// Circular Linked List
class Node {
    public:
    int data;
    Node* next;
    Node(int val) {
        this -> data = val;
        this -> next = NULL;
    }
};
bool isCircular(Node* head) {
    if (head == NULL) {
        return true;
    }
    /*
    // for single node
    if (head -> next== NULL) {
        return false;
    }
    if (head -> next == head) {
        cout<<"Cirular";
        return true;
    } */
    // more than 1 node
    Node* temp = head -> next;
    while (temp!=NULL && temp!=head) {
        temp = temp -> next;
    }
   return (temp == head);
}
int main() {
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);

    head->next = second;
    second->next = third;
    third->next = head; 

    if (isCircular(head)) {
        cout << "List is circular\n";
    } 
    else {
        cout << "List is not circular\n";
    }
    return 0;
}