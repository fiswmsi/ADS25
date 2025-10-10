#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end()); 

    for (int i = 0; i < q; i++) {
        long long l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;

        long long count1 = upper_bound(a.begin(), a.end(), r1) - lower_bound(a.begin(), a.end(), l1);

        long long count2 = upper_bound(a.begin(), a.end(), r2) - lower_bound(a.begin(), a.end(), l2);
        long long left = max(l1, l2);
        long long right = min(r1, r2);
        long long intersect = 0;

        if (left <= right) {
            intersect = upper_bound(a.begin(), a.end(), right) - lower_bound(a.begin(), a.end(), left);
        }

        cout << (count1 + count2 - intersect) << "\n";
    }

    return 0;
}