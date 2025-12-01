#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

Node* newNode(int x){
    Node* t = new Node();
    t->data = x;
    t->left = t->right = NULL;
    return t;
}

Node* insert(Node* root, int x){
    if(root == NULL) return newNode(x);
    if(x < root->data) root->left = insert(root->left, x);
    else root->right = insert(root->right, x);
    return root;
}

int sumLeft(Node* r, bool isLeft){
    if(!r) return 0;
    if(!r->left && !r->right){
        if(isLeft) return r->data;
        else return 0;
    }
    return sumLeft(r->left, true) + sumLeft(r->right, false);
}

int main(){
    int n, x;
    cin >> n;

    Node* root = NULL;
    for(int i=0;i<n;i++){
        cin >> x;
        root = insert(root, x);
    }

    cout << sumLeft(root, false);
    return 0;
}
