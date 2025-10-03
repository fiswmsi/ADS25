#include <iostream>
#include <deque>
using namespace std;
#define ll long long

ll n, mn = 1000000, cnt = 1, m, t = 1;
ll b[1000001];
string s, l, ss, l1;
deque <string> dq;

void ans()
{
    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        cin >> s;

        dq.push_back(s);
    }

    while(m--)
    {
        dq.push_back(dq.front());
        dq.pop_front();
    }

    for(int i = 0; i < n; i++)
        cout << dq[i] << " ";

}

int main()
{
    //cin >> t;

    while(t--)
    {
        ans();
        cout << "\n";
    }    

}