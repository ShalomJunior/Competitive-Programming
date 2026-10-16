#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<pair<int, char>>> adj;

vector<int> bestPath;
string bestLabels;

// DFS that avoids cycles by tracking visited nodes.
void dfs(int u, vector<int>& path, string& labels, vector<bool>& visited) {
    if (u == n - 1) {
        // Update best solution if this path is shorter,
        // or if equal length and lexicographically smaller.
        if (bestPath.empty() || (path.size() < bestPath.size()) ||
            (path.size() == bestPath.size() && labels < bestLabels)) {
            bestPath = path;
            bestLabels = labels;
        }
        return;
    }
    for (auto& edge : adj[u]) {
        int v = edge.first;
        char c = edge.second;
        if (!visited[v]) {
            visited[v] = true;
            path.push_back(v);
            labels.push_back(c);
            dfs(v, path, labels, visited);
            labels.pop_back();
            path.pop_back();
            visited[v] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    adj.resize(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        char c;
        cin >> u >> v >> c;
        // Convert input from 1-indexed to 0-indexed
        u--; v--;
        adj[u].push_back({ v, c });
        adj[v].push_back({ u, c });
    }

    // Prepare for DFS (brute-force search)
    vector<bool> visited(n, false);
    vector<int> path;
    string labels;
    visited[0] = true;
    path.push_back(0);
    dfs(0, path, labels, visited);

    // Output result in the same format as your solution:
    // Line 1: number of edges in the path
    // Line 2: list of vertices (1-indexed)
    // Line 3: concatenated edge labels along the path
    if (bestPath.empty()) {
        cout << -1 << "\n"; // No valid path found
    }
    else {
        cout << bestPath.size() - 1 << "\n";
        for (auto v : bestPath) {
            cout << v + 1 << " ";
        }
        cout << "\n" << bestLabels << "\n";
    }
    return 0;
}
