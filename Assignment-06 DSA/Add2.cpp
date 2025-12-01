#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *prev, *next;
};

void push(Node** head_ref, int new_data)
{
    Node* new_node
        = (Node*)malloc(sizeof(struct Node));

    
    new_node->data = new_data;

    
    new_node->prev = NULL;

    new_node->next = (*head_ref);

    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;

    (*head_ref) = new_node;
}

bool isEvenParity(int x)
{
    int parity = 0;
    while (x != 0) {
        if (x & 1)
            parity++;
        x = x >> 1;
    }

    if (parity % 2 == 0)
        return true;
    else
        return false;
}

void deleteNode(Node** head_ref, Node* del)
{
  
    if (*head_ref == NULL || del == NULL)
        return;

    if (*head_ref == del)
        *head_ref = del->next;

    if (del->next != NULL)
        del->next->prev = del->prev;

    if (del->prev != NULL)
        del->prev->next = del->next;

    free(del);

    return;
}

void deleteEvenParityNodes(
    Node** head_ref)
{
    Node* ptr = *head_ref;
    Node* next;

    while (ptr != NULL) {
        next = ptr->next;

        if (isEvenParity(ptr->data))
            deleteNode(head_ref, ptr);

        ptr = next;
    }
}
void printList(Node* head)
{
    if (head == NULL) {
        cout << "Empty list\n";
        return;
    }

    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}


int main()
{

    Node* head = NULL;


    push(&head, 14);
    push(&head, 9);
    push(&head, 8);
    push(&head, 15);
    push(&head, 18);


     cout << "Original List: ";
    printList(head);

    deleteEvenParityNodes(&head);


    printList(head);
}