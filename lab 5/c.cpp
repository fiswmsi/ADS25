#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define ll long long

int main()
{
    ll n, cnt = 0, k, mncnt = 0, x, y, ans = 0;
    priority_queue<ll, vector <ll>, less<ll> > pq;

    cin >> n>> x;

    for(int i = 0; i < n; i++)
    {
        cin >> k;

        pq.push(k);
    }

    while(x--)
    {
        ans += pq.top();
        pq.push(pq.top() - 1);
        pq.pop();
    }


        cout << ans;

}