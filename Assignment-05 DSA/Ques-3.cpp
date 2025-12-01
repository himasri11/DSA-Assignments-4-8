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
int getlength(Node* head) {
    int count = 0;
    while (head!=NULL) {
        count++;
        head = head -> next;
    }
    return count;
}
Node* middleElement(Node* head) {
    int len = getlength(head);
    int ans = len/2;
    Node* temp = head;
    int cnt = 0;
    while (cnt<ans) {
        temp = temp -> next;
        cnt++;
    }
    return temp;
}