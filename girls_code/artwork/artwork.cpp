#include <bits/stdc++.h>

using namespace std;

int n, links;
vector<vector<int>> adj;
vector<bool> visited;

void dfs(int u)
{
    visited[u] = true;
    for (auto &v : adj[u])
    {
        if (visited[v])
            continue;

        dfs(v);
    }
}

int main()
{
    cin >> n >> links;
    adj.resize(n + 1);
    visited.resize(n + 1);
    for (int i = 0; i < links; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int sm = 0;

    for (int i = 1; i < n + 1; i++)
    {
        if (visited[i])
            continue;
        dfs(i);
        sm++;
    }

    cout << sm - 1;
}