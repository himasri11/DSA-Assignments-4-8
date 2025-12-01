#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int val) {
        this -> data = val;
        this -> next = NULL;
    }
};
Node* kReverse(Node* head,int K) {
    if (head == NULL) {
        return NULL;
    }
    Node* curr = head;
    Node* prev = NULL;
    Node* forward = NULL;
    int count = 0;
    while (curr!=NULL && count<K) {
        forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
        count++;
    }
    if (forward != NULL) {
        head -> next = kReverse(forward,K);
    }
    return prev;
}
void Insert(Node* &head,int val) {
    Node* newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp -> next != NULL) {
        temp = temp -> next;
    }
    temp -> next = newNode;
    return;
}
void print(Node* head) {
    Node* temp = head;
    while (temp!=NULL) {
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
    return;
}
int main() {
    Node* head = NULL;
    for (int i=1;i<=9;i++) {
        Insert(head,i);
    }
    print(head);
    int K=3;
    head = kReverse(head,K);
    print(head);
    return 0;
}