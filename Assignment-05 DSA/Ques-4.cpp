#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int value) {
        this -> data = value;
        this -> next = NULL;
    }
};
Node* ReverseLinkedList(Node* head) {
        if (head == NULL || head -> next == NULL) {
            return head;
        }
        Node* curr = head;
        Node* prev = NULL;
        Node* forward = NULL;
        while (curr!=NULL) {
            forward = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }