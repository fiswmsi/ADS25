#include <iostream>
#include <math.h>
using namespace std;
#define ll long long

ll n = 3, mn = 1000000, cnt = 0, m, cnt1 = 0, k = 3;
ll b[10000001], ans[10000001];
string s, l, ss, l1;

int main()
{
    cin >> n;

    if(n ==1)
        cout << "NO";
    else if(n == 2 || n == 3)
        cout << "YES";
    else
    {
        for(int i = 3; i <= sqrt(n); i += 2)
        {
            if(n % i == 0)
                cnt++;

            if(cnt != 0)
                break;
        }

        if(cnt == 0 && n% 2 != 0)
            cout << "YES";
        else    
            cout << "NO";
    }
    
}