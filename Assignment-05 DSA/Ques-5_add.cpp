#include <iostream>
using namespace std;
class Node {
    public:
    int coeff;
    int power;
    Node* next;
    Node(int c,int p) {
        this -> coeff = c;
        this -> power = p;
        this -> next = NULL;
    }
};
Node* reverse(Node* head) {
    if (head == NULL || head -> next == NULL) {
        return head;
    }
    Node* prev = NULL;
    Node* forward = NULL;
    Node* curr = head;
    while (curr!=NULL) {
        forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}
Node* addPolynomials(Node* poly1,Node* poly2) {
    Node* result = NULL;
    Node* tail = NULL;
    while (poly1 && poly2) {
        if (poly1-> power == poly2-> power) {
            int sumCoeff = poly1 -> coeff + poly2 -> coeff;
            if (sumCoeff!=0) {
                Node* newNode = new Node(sumCoeff, poly1 -> power);
                if (!result) {
                    result = newNode;
                    tail = newNode;
                }
                else {
                    tail -> next = newNode;
                    tail = newNode;
                }
            }
            poly1 = poly1 -> next;
            poly2 = poly2 -> next;
        }
        else if (poly1-> power > poly2 -> power) {
            Node* newNode = new Node(poly1-> coeff,poly1 -> power);
            if (!result) {
                result = newNode;
                tail = newNode;
            }
            else {
                tail -> next = newNode;
                tail = newNode;
            }
            poly1 = poly1 -> next;
        }
        else {
            Node* newNode = new Node(poly2-> coeff,poly2 -> power);
            if (!result) {
                result = newNode;
                tail = newNode;
            }
            else {
                tail -> next = newNode;
                tail = newNode;
            }
            poly2 = poly2 -> next;
        }  
    }
    while (poly1) {
        Node* newNode = new Node(poly1-> coeff, poly1-> power) ;
        tail -> next = newNode;
        tail = newNode;
        poly1 = poly1-> next;
    }
    while (poly2) {
        Node* newNode = new Node(poly2 -> power,poly2 -> coeff);
        tail -> next = newNode;
        tail = newNode;
        poly2 = poly2 -> next;
    }
    return result;
}
void printPoly(Node* poly) {
    while (poly) {
        cout << poly->coeff << "x^" << poly->power;
        poly = poly->next;
        if (poly) cout << " + ";
    }
    cout << endl;
}
int main() {
    // First polynomial: 5x^2 + 4x^1 + 2
    Node* poly1 = new Node(5, 2);
    poly1->next = new Node(4, 1);
    poly1->next->next = new Node(2, 0);

    // Second polynomial: 5x^1 + 5
    Node* poly2 = new Node(5, 1);
    poly2->next = new Node(5, 0);

    Node* result = addPolynomials(poly1, poly2);
    cout << "Resultant Polynomial: ";
    printPoly(result);
    return 0;
}
