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
Node* rotateList(Node* head,int k) {
    if (head == NULL || k==0 || head-> next == NULL) {
        return head;
    }
    int length = 0;
    Node* temp = head;
    while (temp!= NULL) {
        length++;
        temp = temp -> next;
    }
   k = k % length;
   if (k==0) {
        return head;
   }
   Node* curr = head;
   for (int i=1;i<k;i++) {
        curr = curr -> next;
   }
   Node* newHead = curr -> next;
   curr -> next = NULL;
   Node* end = newHead;
   while (end-> next!=NULL) {
    end = end -> next;
   }
   end -> next = head;
   return newHead;
}
Node* print(Node* head) {
    while (head!=NULL) {
        cout<<head -> data<<" ";
        head = head -> next;
    }
    cout<<endl;
}
int main() {
    Node* head = new Node(10);
    Node* node1 = new Node(20);
    Node* node2 = new Node(30);
    Node* node3 = new Node(40); 
    Node* node4 = new Node(50);
    int k=4;
    head-> next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = NULL;
    head = rotateList(head,k);
    cout<<"Rotated list";
    print(head);
    return 0;
}