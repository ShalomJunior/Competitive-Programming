#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<int>> adj;
vector<bool> visited;

vector<int> temp;
vector<int> dfs(int u)
{
    visited[u] = true;
    temp.push_back(u);
    for (auto &v : adj[u])
    {
        if (visited[v])
            continue;
        dfs(v);
    }

    return temp;
}

int main()
{
    cin >> n >> m;

    adj.resize(n + 1);
    visited.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a;
        cin >> a;
        adj[a].push_back(a + 1);
        adj[a + 1].push_back(a);
    }

    vector<int> res;
    for (int i = 1; i < n + 1; i++)
    {
        temp = vector<int>();
        if (visited[i])
            continue;

        auto v = dfs(i);
        for (int k = v.size() - 1; k >= 0; k--)
            res.push_back(v[k]);
    }

    for (auto &b : res)
        cout << b << " ";

    cout << endl;
}