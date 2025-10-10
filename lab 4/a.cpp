#include <iostream>
#include <string>
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

bool checkPath(Node* root, const string& path) {
    Node* cur = root;
    for (int i = 0; i < (int)path.size(); i++) {
        if (!cur) return false;
        if (path[i] == 'L') cur = cur->left;
        else if (path[i] == 'R') cur = cur->right;
    }
    return cur != NULL;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    Node* root = NULL;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        insert(root, x);
    }

    for (int i = 0; i < M; i++) {
        string path;
        cin >> path;
        if (checkPath(root, path)) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}