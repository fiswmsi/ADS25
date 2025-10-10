#include <iostream>
using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int v) : val(v), left(NULL), right(NULL) {}
};

void insert(Node*& root, int v) {
    if (!root) {
        root = new Node(v);
        return;
    }
    if (v < root->val) insert(root->left, v);
    else insert(root->right, v);
}

Node* findNode(Node* root, int x) {
    if (!root) return NULL;
    if (root->val == x) return root;
    if (x < root->val) return findNode(root->left, x);
    return findNode(root->right, x);
}

int countNodes(Node* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    Node* root = NULL;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        insert(root, x);
    }

    int X;
    cin >> X;

    Node* sub = findNode(root, X);
    cout << countNodes(sub) << "\n";

    return 0;
}