#include<iostream>
#include<vector>
#include<queue>
#include<math.h>
using namespace std;

#define ll long long


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, cnt = 0, k, mncnt = 0, x, y = 0, ans = 0, m;
    string s;
    priority_queue<ll, vector <ll>, greater<ll> > pq;

    cin >> n >> m;

    while(n--)
    {
        cin >> s;
        
        if(s == "print")
            cout << ans << "\n";
        else    
        {
            cin >> k;
             
            if (pq.size() == m)
            {
                ans -= pq.top();
                
                x = pq.top(); pq.pop();

                pq.push(max(k , x));
                ans += max(k, x);
            }
            else
            {
                pq.push(k);
                ans += k;
            }
        }
    }
    return 0;
}