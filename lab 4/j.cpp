#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> res;

void build(vector<int>& a, int l, int r) {
    if (l > r) return;
    int mid = (l + r) / 2;
    res.push_back(a[mid]);
    build(a, l, mid - 1);
    build(a, mid + 1, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    int n = (1 << N) - 1;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    build(a, 0, n - 1);
    
    for (int i = 0; i < res.size(); i++) 
        cout << res[i] << " ";
}