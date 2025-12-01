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
int DeleteKey(Node* &head,int key) {
    if (head == NULL) {
        cout<<"List is empty";
        return 0;
    }
        int count = 0;
        Node* temp;
        while (head!=NULL && head -> data == key) {
            temp = head;
            head = head -> next;
            delete temp;
            count++;
        }
        Node* curr = head;
        Node* prev = NULL;
        while (curr != NULL) {
        if (curr ->data == key) {
            count++;
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        } else {
            prev = curr;
            curr = curr->next;
        }
    }
    return count;
}