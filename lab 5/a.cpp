#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define ll long long

int main()
{
    ll n, cnt = 0, k, mncnt = 0;
    priority_queue<ll, vector <ll>, greater<ll> > pq;

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> k;

        pq.push(k);
    }

    while(pq.size() > 1)
    {
        cnt = 0;

        cnt += pq.top(); pq.pop();
        cnt += pq.top(); pq.pop();

        mncnt += cnt;

        pq.push(cnt);
    }

    cout << mncnt;

}