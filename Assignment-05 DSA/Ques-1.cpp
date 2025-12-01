#include <iostream>
using namespace std;
class Node{
    public:
        int data;
        Node* next;
        Node(int d) {
            this -> data = d;
            this -> next = NULL;
        }
};
void InsertAtBeg(Node* &head,int d) {
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;  
}
void InsertAtEnd(Node* &head,int d) {
    Node* newNode = new Node(d);
    if (head == NULL) {
        head =newNode;
        return;
    }
    Node* temp = head;
    while (temp -> next != NULL) {
        temp = temp -> next;
    }
    temp -> next = newNode;
}
void InsertAtMiddle(Node* &head,int d,int pos) {
    if (pos == 1) {
        Node* newNode = new Node(d);
        newNode -> next = head;
        head = newNode;
        return;
    }
    int cnt = 0;
    Node* temp = head;
    while (cnt<pos-1 && temp!=NULL) {
        temp = temp -> next;
        cnt++;
    }
    if (temp==NULL) {
        cout<<"Position out of range";
    }
    if (temp -> next == NULL) {
        InsertAtEnd(temp,d);
        return;
    }
    Node* newNode = new Node(d);
    newNode -> next = temp -> next;
    temp -> next = newNode;
}
void deleteAtBeginning(Node* &head) {
    Node* temp = head;
    head = temp -> next;
    delete temp;
}
void deleteAtEnd(Node* &head) {
    if (head == NULL) {
        return;
    }
    if (head -> next == NULL) {
        delete head;
        head = NULL;
        return;
    }
    Node* temp = head;
    while (temp-> next-> next!= NULL) {
        temp = temp -> next;
    }
    delete temp -> next;
    temp -> next = NULL;
}
void deleteAtSpecific(Node* &head, int num) {
    if (head == NULL) {
        cout<<"List is empty"<<endl;
        return;
    }
    else {
        Node* temp = head;
        Node* pre = NULL;
        while (temp!=NULL && temp -> data !=num) {
            pre = temp;
            temp = temp -> next;
        }
            if (temp == NULL) {
                cout<<"Element not found"<<endl;
                return;
            }
            if (temp == head) {
                head = head -> next;
                delete temp;
            }
            else if (temp -> next == NULL) {
                pre -> next = NULL;
                delete temp;
            }
            else {
                pre -> next = temp -> next;
                delete temp;
            }        
    }
}
void search(Node* head,int val) {
    if (head == NULL) {
        return;
    }
    int pos = 1;
    Node* temp = head;
    while (temp!=NULL) {
        if (temp -> data == val) {
            cout<<"Element found at position: "<<pos;
            return;
        }
        pos++;
        temp = temp -> next;
    }
    cout<<"Element not found";
}
void print(Node* &head) {
    Node* temp = head;
    while (temp!=NULL) {
        cout<<temp->data<<" ";
        temp = temp -> next;
    }
}
int main() {
    Node* head = NULL;
    int choice, value, pos;
    do {
        cout<<"1. Insert at the beginning"<<endl;
        cout<<"2. Insertion at the end"<<endl;
        cout<<"3. Insertion in between"<<endl;
        cout<<"4. Deletion from the beginning"<<endl;
        cout<<"5. Deletion from the end"<<endl;
        cout<<"6. Deletion of a specific node"<<endl;
        cout<<"7. Search for a node and display its position from head"<<endl;
        cout<<"8. Display all the nodes"<<endl;
        cout<<"9. Exit"<<endl;
        cout<<"Enter your choice: "<<endl;
        cin>>choice;
        switch(choice) {
            case 1: 
                cout << "Enter value: ";
                cin >> value;
                InsertAtBeg(head, value);
                break;
            case 2: 
                cout << "Enter value: ";
                cin >> value;
                InsertAtEnd(head, value);
                break;
            case 3:
                cout << "Enter value: ";
                cin >> value;
                cout << "Enter position: ";
                cin >> pos;
                InsertAtMiddle(head, value, pos);
                break;  
            case 4:
                deleteAtBeginning(head);
                break;

            case 5:
                deleteAtEnd(head);
                break;

            case 6:
                cout << "Enter value to delete: ";
                cin >> value;
                deleteAtSpecific(head, value);
                break;

            case 7:
                cout << "Enter value to search: ";
                cin >> value;
                search(head, value);
                cout << endl;
                break;

            case 8:
                cout << "Linked List: ";
                print(head);
                cout << endl;
                break;

            case 9:
                cout << "Exiting program" << endl;
                break;

            default:
                cout << "Invalid choice" << endl;
        }
    }
    while(choice != 9);
}