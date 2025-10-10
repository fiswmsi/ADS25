#include <iostream>
#include <queue>
using namespace std;

int leftChild[1005], rightChild[1005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i <= n; i++) {
        leftChild[i] = 0;
        rightChild[i] = 0;
    }

    for (int i = 0; i < n - 1; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        if (z == 0) leftChild[x] = y;
        else rightChild[x] = y;
    }

    queue<pair<int, int> > q;
    q.push(make_pair(1, 1));

    int levelCount[1005] = {0};
    int maxLevel = 0;

    while (!q.empty()) {
        int node = q.front().first;
        int level = q.front().second;
        q.pop();

        levelCount[level]++;
        if (level > maxLevel) maxLevel = level;

        if (leftChild[node]) q.push(make_pair(leftChild[node], level + 1));
        if (rightChild[node]) q.push(make_pair(rightChild[node], level + 1));
    }

    int maxWidth = 0;
    for (int i = 1; i <= maxLevel; i++)
        if (levelCount[i] > maxWidth) maxWidth = levelCount[i];

    cout << maxWidth << "\n";
    return 0;
}