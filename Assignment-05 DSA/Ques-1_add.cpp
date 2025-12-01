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
int getlength(Node* head) {
    Node* temp = head;
    int cnt=0;
    while (temp!=NULL) {
        cnt++;
        temp = temp -> next;
    }
    return cnt;
}
Node* intersection(Node* head1,Node* head2) {
    Node* a = head1;
    Node* b = head2;
    int len1 = getlength(head1);
    int len2 = getlength(head2);
    if (len1>len2) {
        int len = len1-len2;
        for (int i=0;i<len;i++) {
            a = a -> next;
        }
    }
    else {
        int len = len2 - len1;
        for (int i=0;i<len;i++) {
            b = b -> next;
        }
    }
    while (a!=NULL && b!=NULL) {
        if (a==b) {
            return a;
        }
        a = a -> next;
        b = b -> next;
    }
    return NULL;
}