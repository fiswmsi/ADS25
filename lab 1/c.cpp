#include <iostream>
#include <string>
using namespace std;
#define ll long long

ll n;
string s, l, ss, l1;

string procces(string s)
{
    string ans;
    char c;

    for(int i = 0; i < s.size(); i++)
    {
        c = s[i];

        if(c == '#')
        {
            if(!ans.empty())
                ans.pop_back();
        }
        else
            ans.push_back(c);
    }


    return ans;
}
int main()
{
    cin >> s >> l;

    if(procces(s) == procces(l))
        cout << "Yes";
    else    
        cout << "No";
}