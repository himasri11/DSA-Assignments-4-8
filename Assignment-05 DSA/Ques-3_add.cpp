#include <iostream>
using namespace std;
// Detect cycle- flyod's cycle 
class Node {
    public:
    int data;
    Node* next;
    Node(int val) {
        this -> data = val;
        this -> next = NULL;
    }
};
Node* floydCycle(Node* head) {
    if (head == NULL) {
        return NULL;
    }
    Node* fast = head;
    Node* slow = head;
    while (fast!=NULL && slow!=NULL) {
        fast = fast -> next;
        if (fast!=NULL) fast = fast-> next;
        slow = slow -> next;
        if (slow == fast) {
            return slow;
        }
    }
    return NULL;
}
Node* getStartingNode(Node* head) {
    if (head == NULL) {
        return NULL;
    }
    Node* intersection = floydCycle(head);
    Node* slow = head;
    while (slow!=intersection) {
        slow = slow -> next;
        intersection = intersection -> next;   
    }
    return slow;
}
void removeLoop(Node* head) {
    if (head == NULL) {
        return;
    }
    Node* startOfloop = getStartingNode(head);
    Node* temp = startOfloop;
    while (temp -> next != startOfloop) {
        temp = temp -> next;
    }
    temp -> next = NULL;
}
