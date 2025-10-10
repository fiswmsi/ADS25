#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Pasture {
    long long x1, y1, x2, y2;
};

bool canCatch(const vector<Pasture>& v, long long L, int K) {
    int count = 0;
    for (int i = 0; i < (int)v.size(); i++) {
        if (v[i].x2 <= L && v[i].y2 <= L)
            count++;
    }
    return count >= K;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vector<Pasture> v(N);
    long long maxCoord = 0;

    for (int i = 0; i < N; i++) {
        cin >> v[i].x1 >> v[i].y1 >> v[i].x2 >> v[i].y2;
        maxCoord = max(maxCoord, max(v[i].x2, v[i].y2));
    }

    long long l = 0, r = maxCoord, ans = r;
    while (l <= r) {
        long long mid = (l + r) / 2;
        if (canCatch(v, mid, K)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << ans << "\n";
    return 0;
}