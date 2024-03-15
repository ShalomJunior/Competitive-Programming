#include <bits/stdc++.h>

using namespace std;

string format(string s)
{
    string res;
    for (auto &c : s)
        if (c == '\\')
            continue;
        else
            res += c;

    return res;
}
void solve()
{
    string s;
    cin >> s;
    s = format(s);

    int down = 0;
    int open = 0;
    for (auto c : s)
    {
        if (c == '}')
            open--;
        else
            open++;

        down = max(down, open);
        if (open < 0)
        {
            cout << "INVALID" << endl;
            return;
        }
    }
    if (open != 0)
        cout << "INVALID" << endl;
    else
        cout << down << endl;
}

int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
        solve();
}