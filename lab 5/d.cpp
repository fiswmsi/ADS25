#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define ll long long

int main()
{
    ll n, cnt = 0, k, mncnt = 0, x, y, ans = 0, m;
    priority_queue<ll, vector <ll>, greater<ll> > pq;

    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        cin >> k;

        pq.push(k);
    }

    while(m > pq.top() && pq.size() > 1)
    {
        x = pq.top(); pq.pop();
        y = pq.top(); pq.pop();

        cnt = (x + (y * 2));

        pq.push(cnt);
        ans++;
    }

    if (pq.top() >= m) cout << ans;
    else cout << -1;

}