#include <iostream>
#include <queue>
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

    queue<pair<Node*, int> > q;
    q.push(make_pair(root, 1));

    int levelSum[5005] = {0};
    int maxLevel = 0;

    while (!q.empty()) {
        Node* node = q.front().first;
        int level = q.front().second;
        q.pop();

        levelSum[level] += node->val;
        if (level > maxLevel) maxLevel = level;

        if (node->left) q.push(make_pair(node->left, level + 1));
        if (node->right) q.push(make_pair(node->right, level + 1));
    }

    cout << maxLevel << "\n";
    for (int i = 1; i <= maxLevel; i++) cout << levelSum[i] << " ";
    cout << "\n";

    return 0;
}