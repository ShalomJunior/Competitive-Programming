#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<int>> children;
vector<vector<int>> parents;
vector<bool> visited;

void dfs(int u)
{
    visited[u] = true;
    for (auto &v : children[u])
    {
        if (visited[v])
        {
            cout << "NO";
            exit(EXIT_SUCCESS);
        }

        dfs(v);
    }
}

int main()
{
    cin >> n >> m;

    children.resize(n + 1);
    parents.resize(n + 1);
    visited.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int p, c;
        cin >> p >> c;

        parents[c].push_back(p);
        children[p].push_back(c);

        if (p == c || parents[p].size() > 1)
        {
            cout << "NO";
            return 0;
        }
    }

    // Init process check
    int cn = 0, idx;
    for (int i = 1; i < parents.size(); i++)
    {
        auto p = parents[i];
        if (p.size() == 0)
        {
            cn++;
            idx = i;
        }
        if (cn > 1)
        {
            cout << "NO";
            return 0;
        }
    }

    if (cn == 0)
    {
        cout << "NO";
        return 0;
    }

    dfs(idx);
    cout << "YES";
}