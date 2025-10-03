#include <iostream>
#include <math.h>
using namespace std;
#define ll long long

ll n = 3, mn = 1000000, cnt = 0, m, cnt1 = 0, k = 3;
ll b[10000001], ans[10000001];
string s, l, ss, l1;

int main()
{
    cin >> m;

    b[1] = 2;
    b[2] = 3;
    ans[1] = 3;
    ans[2] = 5;

    for(int i = 5; i < 1000001; i += 2)
    {
        cnt = 0;

        for(int j = 3; j <= sqrt(i); j += 2)
        {
            if(i % j == 0)
                cnt++;

            if(cnt != 0)
                break;

        }

        if(cnt == 0)
        {
            b[n] = i;
            n++;
        }
    }

    cnt = 0;

    for(int i = 5; i <= n; i += 2)
    {
        cnt = 0;

        for(int j = 3; j <= sqrt(i); j += 2)
        {
            if(i % j == 0)
                cnt++;

            if(cnt != 0)
                break;
        }

        if(cnt == 0)
        {
            ans[k] = b[i];
            k++;
        }
    }



    cout << ans[m];
}