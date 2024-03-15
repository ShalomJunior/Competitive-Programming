#include <bits/stdc++.h>

using namespace std;

string gt(string str)
{
    string s;
    for (auto c : str)
        if (c != '0')
            s.push_back(c);

    return s;
}

void solve()
{
    string s;
    cin >> s;
    int d = 0;
    bool end = false;
    while (!end)
    {
        end = true;
        for (int i = 1; i < s.length(); i++)
            if (s[i] == 'c' && s[i - 1] != '0' && s[i - 1] != 'c')
            {
                end = false;
                s[i - 1] = '0';
            }

        s = gt(s);
        d++;
    }

    cout << d - 1 << " " << s << endl;
}

int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
        solve();
}