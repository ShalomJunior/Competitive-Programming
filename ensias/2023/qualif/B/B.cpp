#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> tab;

int find(int x)
{
    if (tab[x] == x)
        return x;
    return tab[x] = find(tab[x]);
}

int main()
{
    cin >> n >> m;

    tab.resize(n + 1);
    for (int i = 1; i <= n; i++)
        tab[i] = i;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a = find(a), b = find(b);
        if (a != b)
            tab[b] = a;
    }

    int sm = 0;
    unordered_map<int, bool> tr;
    for (int i = 1; i <= n; i++)
    {
        int p = find(i);
        if (!tr[p])
            sm++, tr[p] = true;
    }

    cout << sm - 1;

    return 0;
}
