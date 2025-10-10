#include <iostream>
using namespace std;

int a[1000005]; 

bool binarySearch(int n, int x) {
    int l = 0, r = n - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (a[mid] == x) return true;
        else if (a[mid] < x) l = mid + 1;
        else r = mid - 1;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> x;

    if (binarySearch(n, x)) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}