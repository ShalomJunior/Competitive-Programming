#include <bits/stdc++.h>

void dfs_2(int length);

using namespace std;

const int M = 1e9 + 7;
int n, res = 0;

vector<vector<int>> adj;
vector<bool> visited;

void in()
{
    for (int i = 1; i < n + 1; i++)
        visited[i] = false;
}

void dfs(int u, int length, bool init)
{
    cout << "Calling dfs : " << u << " " << length << endl;
    visited[u] = true;
    length++;
    // if (length == n)
    // {
    //     res++, res %= M;
    //     return;
    // }
    for (auto &v : adj[u])
    {
        if (visited[v])
            continue;

        dfs(v, length, false);
        visited[v] = false;
    }

    if (!init)
        if (length < n)
            dfs_2(length);
        else
        {
            cout << "finished : " << u << " " << length << endl;
            res++, res %= M;
        }
    else
        cout << "Shoul over" << endl;
}

void dfs_2(int length)
{
    cout << "Calling dfs_2 : " << length << endl;
    for (int i = 1; i < n + 1; i++)
    {
        if (visited[i])
            continue;

        dfs(i, length, false);
        visited[i] = false;
    }
}
int main()
{
    cin >> n;

    adj.resize(n + 1);
    visited.resize(n + 1);
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i < n + 1; i++)
    {
        in();
        dfs(i, 0, true);
        cout << res << endl;
    }

    cout << "res : " << res << endl;
}