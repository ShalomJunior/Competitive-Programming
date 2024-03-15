#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    for (auto c : s)
    {
        if (c == 'c')
        {
            cout << "Stay Home";
            return 0;
        }
    }
    cout << "Safe";
}