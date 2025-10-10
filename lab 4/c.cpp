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

Node* find(Node* root, int x) {
    if (!root) return NULL;
    if (root->val == x) return root;
    if (x < root->val) return find(root->left, x);
    return find(root->right, x);
}

void preorder(Node* root) {
    if (!root) return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    Node* root = NULL;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        insert(root, x);
    }

    int k;
    cin >> k;

    Node* start = find(root, k);
    preorder(start);
    cout << "\n";
}