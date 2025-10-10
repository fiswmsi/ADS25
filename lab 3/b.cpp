#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canDivide(const vector<long long>& a, int k, long long limit) {
    long long sum = 0;
    int blocks = 1;
    for (int i = 0; i < (int)a.size(); i++) {
        if (sum + a[i] > limit) {
            blocks++;
            sum = a[i];
            if (blocks > k) return false;
        } else {
            sum += a[i];
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    long long l = a[0], r = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > l) l = a[i];
        r += a[i];
    }

    long long ans = r;
    while (l <= r) {
        long long mid = (l + r) / 2;
        if (canDivide(a, k, mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << ans << "\n";
    return 0;
}