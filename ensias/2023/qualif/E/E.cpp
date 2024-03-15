#include <bits/stdc++.h>

using namespace std;

bool compare(pair<string, pair<int, int>> a, pair<string, pair<int, int>> b)
{
    if (a.second.first != b.second.first)
        return a.second.first > b.second.first;
    else
    {
        if (a.second.second != b.second.second)
            return a.second.second < b.second.second;
    }
    return a.first < b.first;
}

int main()
{

    int n;
    cin >> n;
    vector<pair<string, pair<int, int>>> v(n);
    for (int i = 0; i < n; i++)
    {
        string s;
        int e, w;
        cin >> s >> e >> w;
        v[i] = make_pair(s, make_pair(e, w));
    }

    sort(v.begin(), v.end(), compare);

    for (auto p : v)
        cout << p.first << endl;
}