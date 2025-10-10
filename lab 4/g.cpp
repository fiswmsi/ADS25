#include <iostream>
#include <algorithm>
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
    else if (v > root->val) insert(root->right, v);
}

int diameter(Node* root, int& res) {
    if (!root) return 0;
    int left = diameter(root->left, res);
    int right = diameter(root->right, res);
    res = max(res, left + right);
    return max(left, right) + 1;
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

    int res = 0;
    diameter(root, res);
    cout << res + 1 << "\n";
}