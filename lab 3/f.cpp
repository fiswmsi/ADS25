#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];

    sort(a.begin(), a.end());

    vector<long long> prefix(N + 1, 0);
    for (int i = 1; i <= N; i++)
        prefix[i] = prefix[i - 1] + a[i - 1];

    int P;
    cin >> P;
    while (P--) {
        int M;
        cin >> M;

        int idx = upper_bound(a.begin(), a.end(), M) - a.begin();

        cout << idx << " " << prefix[idx] << "\n";
    }

    return 0;
}