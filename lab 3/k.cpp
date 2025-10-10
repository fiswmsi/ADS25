#include <iostream>
using namespace std;

long long a[100005];
long long prefix[100005];

int findIndex(int n, long long value) {
    int l = 1, r = n, ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (prefix[mid] >= value) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++) cin >> a[i];

    prefix[0] = 0;
    for (int i = 1; i <= n; i++)
        prefix[i] = prefix[i - 1] + a[i];

    int ans = n + 1;
    for (int i = 1; i <= n; i++) {
        long long need = prefix[i - 1] + k;
        int j = findIndex(n, need);
        if (j != -1) ans = min(ans, j - i + 1);
    }

    cout << ans << "\n";
    return 0;
}