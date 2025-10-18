#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define ll long long

int main()
{
    ll n, cnt = 0, k, mncnt = 0, x, y;
    priority_queue<ll, vector <ll>, less<ll> > pq;

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> k;

        pq.push(k);
    }

    while(pq.size() > 1)
    {
        y = pq.top(); pq.pop();
        x = pq.top(); pq.pop();

        if(x != y)
            pq.push(y - x);
    }

    if(pq.empty())
        cout << 0;
    else
        cout << pq.top();

}