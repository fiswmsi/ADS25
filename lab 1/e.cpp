#include <iostream>
#include <queue>
#define ll long long
using namespace std;

ll n, m, b, x, moves = 0;
queue<int> boris, nursik;

int main() {

    for (int i = 0; i < 5; i++) {
        cin >> x;

        boris.push(x);
    }

    for (int i = 0; i < 5; i++) {
        cin >> x;

        nursik.push(x);
    }

    while (!boris.empty() && !nursik.empty() && moves < 1000000) {
        moves++;
        int b = boris.front(); boris.pop();
        int n = nursik.front(); nursik.pop();

        if (b == 0 && n == 9) {
            boris.push(b);
            boris.push(n);
        } 
        else if (b == 9 && n == 0) {
            nursik.push(b);
            nursik.push(n);
        } 
        else if (b > n) {
            boris.push(b);
            boris.push(n);
        } 
        else {
            nursik.push(b);
            nursik.push(n);
        }
    }

    if (moves >= 1000000) {
        cout << "blin nichya" << endl;
    } 
    else if (!boris.empty()) {
        cout << "Boris " << moves << endl;
    } 
    else {
        cout << "Nursik " << moves << endl;
    }

    return 0;
}