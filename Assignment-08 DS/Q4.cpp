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

Node* insert(Node* r, int x){
    if(r == NULL) return newNode(x);
    if(x < r->data) r->left = insert(r->left, x);
    else r->right = insert(r->right, x);
    return r;
}

bool checkBST(Node* r, int min, int max){
    if(!r) return true;
    if(r->data <= min || r->data >= max) return false;
    return checkBST(r->left, min, r->data) && checkBST(r->right, r->data, max);
}

int main(){
    int n, x;
    cin >> n;
    Node* root = NULL;

    for(int i=0;i<n;i++){
        cin >> x;
        root = insert(root,x);
    }

    if(checkBST(root,-1000000,1000000)) cout << "YES";
    else cout << "NO";
}
