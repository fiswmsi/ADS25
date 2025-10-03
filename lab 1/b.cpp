#include <iostream>
using namespace std;
#define ll long long

ll n, mn = 1000000, cnt, m;
ll b[1000001];
string s, l, ss, l1;

int main()
{
    cin >> n;

    ll a[n];
    ll ans[n];

    for(int i = 0; i< n; i++)
        cin >> a[i];

    ans[0] = -1;

    for(int i = 1; i < n; i++)
    {
        if(i != 0)
        {
            cnt = 0;

            for(int j = i - 1; j >= 0; j--)
            {
                if(a[j] <= a[i])
                {
                    m = a[j];
                    cnt++;
                    break;
                }
                
            }

            if(cnt == 0)
                ans[i] = -1;
            else    
                ans[i] = m;
        }
        
    }

    for(int i = 0; i < n; i++)
        cout << ans[i] << " ";

}