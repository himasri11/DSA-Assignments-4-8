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

Node* insertBST(Node* root, int x) {
    if (root == NULL) return newNode(x);
    if (x < root->data) root->left = insertBST(root->left, x);
    else root->right = insertBST(root->right, x);
    return root;
}

void preorder(Node* r) {
    if (!r) return;
    cout << r->data << " ";
    preorder(r->left);
    preorder(r->right);
}

void inorder(Node* r) {
    if (!r) return;
    inorder(r->left);
    cout << r->data << " ";
    inorder(r->right);
}

void postorder(Node* r) {
    if (!r) return;
    postorder(r->left);
    postorder(r->right);
    cout << r->data << " ";
}

Node* searchRec(Node* r, int x) {
    if (!r || r->data == x) return r;
    if (x < r->data) return searchRec(r->left, x);
    return searchRec(r->right, x);
}

Node* searchNonRec(Node* r, int x) {
    while (r) {
        if (r->data == x) return r;
        if (x < r->data) r = r->left;
        else r = r->right;
    }
    return NULL;
}

Node* minNode(Node* r) {
    while (r && r->left) r = r->left;
    return r;
}

Node* maxNode(Node* r) {
    while (r && r->right) r = r->right;
    return r;
}

Node* inorderSuccessor(Node* root, Node* x) {
    if (x->right) return minNode(x->right);
    Node* succ = NULL;
    Node* cur = root;
    while (cur) {
        if (x->data < cur->data) {
            succ = cur;
            cur = cur->left;
        } else if (x->data > cur->data) {
            cur = cur->right;
        } else break;
    }
    return succ;
}

Node* inorderPredecessor(Node* root, Node* x) {
    if (x->left) return maxNode(x->left);
    Node* pre = NULL;
    Node* cur = root;
    while (cur) {
        if (x->data > cur->data) {
            pre = cur;
            cur = cur->right;
        } else if (x->data < cur->data) {
            cur = cur->left;
        } else break;
    }
    return pre;
}

int main() {
    Node* root = NULL;
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        root = insertBST(root, x);
    }

    preorder(root);
    cout << endl;
    inorder(root);
    cout << endl;
    postorder(root);
    cout << endl;

    int key;
    cin >> key;

    Node* r1 = searchRec(root, key);
    Node* r2 = searchNonRec(root, key);

    Node* mn = minNode(root);
    Node* mx = maxNode(root);

    Node* s = inorderSuccessor(root, r1);
    Node* p = inorderPredecessor(root, r1);

    if (mn) cout << mn->data << endl;
    if (mx) cout << mx->data << endl;
    if (s) cout << s->data << endl;
    if (p) cout << p->data << endl;

    return 0;
}
