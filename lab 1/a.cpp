#include <iostream>
#include <deque>
using namespace std;
#define ll long long

ll n, mn = 1000000, cnt = 1, m, t = 1;
ll b[1000001];
string s, l, ss, l1;
deque <ll> dq;

void ans()
{
    cin >> n;

    cnt = 1;
    
    for(int i = 1; i <= n; i++)
        dq.push_back(i);

    for(int i = 1; i <= n; i++)
    {
        m = i;

        while(m--)
        {
            dq.push_back(dq.front());
            dq.pop_front();
        }

        b[dq.front()] = cnt;
        cnt++;
        dq.pop_front();
    }

    for(int i = 1; i <= n; i++)
        cout << b[i] << " ";

    dq.clear();

}

int main()
{
    cin >> t;

    while(t--)
    {
        ans();
        cout << "\n";
    }    

}