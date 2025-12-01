#include <iostream>
#include <vector>
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

vector<Node*> generate(int start, int end) {
    vector<Node*> ans;

    if (start > end) {
        ans.push_back(NULL);
        return ans;
    }

    for (int i = start; i <= end; i++) {
        vector<Node*> leftTrees = generate(start, i - 1);
        vector<Node*> rightTrees = generate(i + 1, end);

        for (int l = 0; l < leftTrees.size(); l++) {
            for (int r = 0; r < rightTrees.size(); r++) {
                Node* root = newNode(i);
                root->left = leftTrees[l];
                root->right = rightTrees[r];
                ans.push_back(root);
            }
        }
    }
    return ans;
}

vector<Node*> generateTrees(int n) {
    return generate(1, n);
}

void printTree(Node* r){
    if(!r){
        cout << "null ";
        return;
    }
    cout << r->data << " ";
    printTree(r->left);
    printTree(r->right);
}

int main(){
    int n;
    cin >> n;

    vector<Node*> res = generateTrees(n);

    for (int i = 0; i < res.size(); i++) {
        printTree(res[i]);
        cout << endl;
    }
}
