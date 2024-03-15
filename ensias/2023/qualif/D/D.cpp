#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;

int best;
bool trap;
int room;

void dfs(vector<vector<int>> &adj, int sm, int u, int p)
{
    sm++;

    if (sm == best)
        trap = true;
    else if (sm > best)
        best = sm, room = u,
        trap = false;

    for (const auto &v : adj[u])
    {
        if (v == p)
            continue;

        dfs(adj, sm, v, u);
    }
}

void solve()
{
    int N;
    cin >> N;
    vector<vector<int>> adj(N + 1);
    for (int i = 1; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(adj, 0, 1, -1);
    if (trap)
        cout << "it was a trap!" << endl;
    else
        cout << room << endl;
}

int main()
{
    freopen("azuz.in", "r", stdin);

    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        best = 0;
        trap = false;
        room = 1;
        solve();
    }
}