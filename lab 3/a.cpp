#include <iostream>
#include <vector>
using namespace std;

int binarySearchRow(const vector<int>& row, int target, bool ascending) {
    int l = 0, r = (int)row.size() - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (row[mid] == target) return mid;
        if (ascending) {
            if (row[mid] < target) l = mid + 1;
            else r = mid - 1;
        } else {
            if (row[mid] > target) l = mid + 1;
            else r = mid - 1;
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;  
    vector<int> queries(t);
    for (int i = 0; i < t; i++) cin >> queries[i];

    int n, m;
    cin >> n >> m;
    
    vector< vector<int> > matrix(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < t; i++) {
        int q = queries[i];
        bool found = false;
        for (int i = 0; i < n && !found; i++) {
            bool ascending = (i % 2 == 1); 
            int col = binarySearchRow(matrix[i], q, ascending);
            if (col != -1) {
                cout << i << " " << col << "\n"; 
                found = true;
            }
        }
        if (!found) cout << -1 << "\n";
    }

    return 0;
}