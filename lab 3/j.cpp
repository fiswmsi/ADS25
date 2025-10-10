#include <iostream>
using namespace std;

long long bags[10005];

bool canSteal(int N, long long H, long long K) {
    long long hours = 0;
    for (int i = 0; i < N; i++) {
        hours += (bags[i] + K - 1) / K; 
        if (hours > H) return false;   
    }
    return hours <= H;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    long long H;
    cin >> N >> H;

    long long maxGold = 0;
    for (int i = 0; i < N; i++) {
        cin >> bags[i];
        if (bags[i] > maxGold) maxGold = bags[i];
    }

    long long left = 1, right = maxGold, ans = right;

    while (left <= right) {
        long long mid = (left + right) / 2;
        if (canSteal(N, H, mid)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << ans << "\n";
    return 0;
}