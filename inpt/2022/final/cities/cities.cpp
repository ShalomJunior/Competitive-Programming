#include <bits/stdc++.h>

using namespace std;

int n, m, sm;
vector<vector<int>> adj;
vector<bool> visited;

void dfs(int u)
{
    visited[u] = true;
    sm++;
    for (auto &v : adj[u])
    {
        if (visited[v])
            continue;
        dfs(v);
    }
}
int main()
{

    cin >> n >> m;
    adj.resize(n + 1);
    visited.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i < n; i++)
    {
        int t;
        cin >> t;
        if (t)
            visited[i] = true;
    }

    sm = 0;
    for (int i = 1; i < n + 1; i++)
    {
        if (visited[i])
            continue;
        dfs(i);
    }
    cout << sm << endl;
}