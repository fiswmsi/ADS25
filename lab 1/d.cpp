#include <iostream>
#include <string>
using namespace std;
#define ll long long
ll n, cnt = 0, fr, sc;
string s, l, ss, l1;
char c;

bool procces(string s)
{
    n = s.size();

    if(n % 2 != 0)
        return false;
    else if(s.size() == 0)
        return true;
    else
    {    
        for(int i = 0; i < n; )
        {
            if(s.empty() || cnt == n + 1)
                break;

            c = s[0];

            sc = s.rfind(c);
            fr = s.find(c);

            if((sc - fr) % 2 != 0)
            {
                s.erase(sc, 1);
                s.erase(fr, 1);
            }
            else
            {
                return false;
                break;
            }
        }

        if(s.empty())
            return true;
        else    
            return false;
    }
}
int main()
{
    cin >> s;

    if(procces(s))
        cout << "YES";
    else
        cout << "NO";
}