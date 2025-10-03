#include <iostream>
#include <math.h>
#include <deque>
using namespace std;
#define ll long long

ll n = 3, mn = 1000000, cnt = 0, m, cnt1 = 0, k = 3;
ll b[10000001], ans[10000001];
string s, l, ss, l1;
deque<ll>dq;

int main()
{
    while(cin >> s)
    {   
        if(s == "!")
            return 0;

        if(s == "+")
        {
            cin >> n;
            dq.push_front(n);
        }
        else if(s == "-")
        {
            cin >> n;
            dq.push_back(n);
        }
        else if(s == "*")
        {
            if(dq.size() == 0)
                cout << "error" << endl;
            else if(dq.size() == 1)
            {
                cout << dq.front() + dq.front() << endl;
                dq.pop_front();
            }
            else
            {
                cout << dq.front() + dq.back() << endl;

                dq.pop_front();
                dq.pop_back();
            }
        }

    }
    
}