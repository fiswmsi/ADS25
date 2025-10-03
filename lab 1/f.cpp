#include <iostream>
#include <math.h>
using namespace std;
#define ll long long

ll n = 3, mn = 1000000, cnt = 0, m, cnt1 = 0;
ll b[10000001];
string s, l, ss, l1;

int main()
{
    cin >> m;

    b[1] = 2;
    b[2] = 3;

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

    cout << b[m];
}