#include <iostream>
using namespace std;

long long prefix[200005]; 
long long a[200005];    
long long b[200005];      

int findBlock(long long x, int N) {
    int l = 1, r = N, ans = N;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (prefix[mid] >= x) {
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

    int N, M;
    cin >> N >> M;

    prefix[0] = 0;
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
        prefix[i] = prefix[i - 1] + a[i];
    }

    for (int i = 0; i < M; i++) cin >> b[i];

    for (int i = 0; i < M; i++) {
        cout << findBlock(b[i], N) << "\n";
    }

    return 0;
}