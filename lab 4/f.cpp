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

int countTriangles(Node* root) {
    if (!root) return 0;
    int leftTri = countTriangles(root->left);
    int rightTri = countTriangles(root->right);
    int cur = (root->left && root->right) ? 1 : 0;
    return leftTri + rightTri + cur;
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

    cout << countTriangles(root) << "\n";
    return 0;
}