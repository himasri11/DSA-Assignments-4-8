#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

Node* newNode(int x) {
    Node* t = new Node();
    t->data = x;
    t->left = t->right = NULL;
    return t;
}

Node* insertBST(Node* r, int x) {
    if (r == NULL) return newNode(x);
    if (x < r->data) r->left = insertBST(r->left, x);
    else if (x > r->data) r->right = insertBST(r->right, x);
    return r;
}

Node* minNode(Node* r) {
    while (r && r->left) r = r->left;
    return r;
}

Node* deleteBST(Node* r, int x) {
    if (r == NULL) return r;

    if (x < r->data) r->left = deleteBST(r->left, x);
    else if (x > r->data) r->right = deleteBST(r->right, x);
    else {
        if (!r->left && !r->right) {
            delete r;
            return NULL;
        }
        else if (!r->left) {
            Node* t = r->right;
            delete r;
            return t;
        }
        else if (!r->right) {
            Node* t = r->left;
            delete r;
            return t;
        }
        Node* t = minNode(r->right);
        r->data = t->data;
        r->right = deleteBST(r->right, t->data);
    }
    return r;
}

int maxDepth(Node* r) {
    if (!r) return 0;
    int L = maxDepth(r->left);
    int R = maxDepth(r->right);
    return (L > R ? L : R) + 1;
}

int minDepth(Node* r) {
    if (!r) return 0;
    int L = minDepth(r->left);
    int R = minDepth(r->right);
    if (!r->left) return R + 1;
    if (!r->right) return L + 1;
    return (L < R ? L : R) + 1;
}

void inorder(Node* r) {
    if (!r) return;
    inorder(r->left);
    cout << r->data << " ";
    inorder(r->right);
}

int main() {
    Node* root = NULL;
    int n, x;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        root = insertBST(root, x);
    }

    inorder(root);
    cout << endl;

    int del;
    cin >> del;
    root = deleteBST(root, del);

    inorder(root);
    cout << endl;

    cout << maxDepth(root) << endl;
    cout << minDepth(root) << endl;

    return 0;
}
