// #include <bits/stdc++.h>
// using namespace std;

// const int INF = 1e9;

// int n, m;
// vector<vector<pair<int, char>>> adj(100);

// vector<int> bestPath;
// string bestLabels;

// // DFS that avoids cycles by tracking visited nodes.
// void dfs(int u, vector<int>& path, string& labels, vector<bool>& visited) {
//     if (u == n - 1) {
//         // Update best solution if this path is shorter,
//         // or if equal length and lexicographically smaller.
//         if (bestPath.empty() || (path.size() < bestPath.size()) ||
//             (path.size() == bestPath.size() && labels < bestLabels)) {
//             bestPath = path;
//             bestLabels = labels;
//         }
//         return;
//     }
//     for (auto& edge : adj[u]) {
//         int v = edge.first;
//         char c = edge.second;
//         if (!visited[v]) {
//             visited[v] = true;
//             path.push_back(v);
//             labels.push_back(c);
//             dfs(v, path, labels, visited);
//             labels.pop_back();
//             path.pop_back();
//             visited[v] = false;
//         }
//     }
// }
// string brute() {
//     // Prepare for DFS (brute-force search)
//     vector<bool> visited(n, false);
//     vector<int> path;
//     string labels;
//     visited[0] = true;
//     path.push_back(0);
//     dfs(0, path, labels, visited);

//     // Output result in the same format as your solution:
//     // Line 1: number of edges in the path
//     // Line 2: list of vertices (1-indexed)
//     // Line 3: concatenated edge labels along the path
//     if (bestPath.empty()) {
//         return "-1";
//         //cout << -1 << "\n"; // No valid path found
//     }
//     else {
//         // cout << bestPath.size() - 1 << "\n";
//         // for (auto v : bestPath) {
//         //     cout << v + 1 << " ";
//         // }
//         //cout << "\n" << bestLabels << "\n";
//         return bestLabels;
//     }
//     cout << "shit" << endl;
// }
// void solve() {
//     srand(time(0));  // seed random generator

//     //int n, m;
//     // If the generator is run without input, use default values.
//     if (!(cin >> n >> m)) {
//         n = 10;
//         m = 15;
//     }
//     // Ensure m is at least n-1 (to guarantee connectivity)
//     m = max(m, n - 1);

//     vector<tuple<int, int, char>> edges;

//     // Create a random spanning tree (n-1 edges)
//     for (int i = 1; i < n; i++) {
//         int u = i;
//         int v = rand() % i; // choose a random vertex from 0 to i-1
//         char c = 'a' + rand() % 26; // random character from 'a' to 'z'
//         edges.push_back({ u, v, c });
//     }

//     int extra = m - (n - 1);
//     set<pair<int, int>> used;
//     for (auto& edge : edges) {
//         int u, v; char c;
//         tie(u, v, c) = edge;
//         if (u > v) swap(u, v);
//         used.insert({ u,v });
//     }

//     // Add extra random edges that are not already present.
//     while (extra > 0) {
//         int u = rand() % n;
//         int v = rand() % n;
//         if (u == v) continue; // skip self-loops
//         if (u > v) swap(u, v);
//         if (used.count({ u,v })) continue;
//         char c = 'a' + rand() % 26;
//         edges.push_back({ u, v, c });
//         used.insert({ u,v });
//         extra--;
//     }

//     // Shuffle edges to randomize order
//     random_shuffle(edges.begin(), edges.end());
//     // Output in the expected format (converting vertices to 1-indexed)
//     //cout << n << " " << m << "\n";
//     cout << "end" << endl;
//     for (auto& edge : edges) {
//         //int u, v; char c;
//         //tie(u, v, c) = edge;
//         //cout << u + 1 << " " << v + 1 << " " << c << "\n";
//     }
//     //int n, m;
//     //cin >> n >> m;
//     //vector<vector<pair<int, char>>> adj(n);
//     cout << "end#" << endl;
//     cout << "n = " << n << " " << m << "\n";
//     cout << edges.size() << endl;
//     adj.resize(n);
//     for (int i = 0; i < m; i++) {
//         int u, v;
//         char c;
//         tie(u, v, c) = edges[i];

//         //cin >> u >> v >> c;
//         //--u;
//         //--v;
//         cout << u << " " << v << " " << c << "\n";
//         adj[u].push_back({ v, c });
//         adj[v].push_back({ u, c });
//     }
//     vector<char> L(n, 'z');
//     vector<char> C(n, 'z' + 1);
//     vector<bool> vis(n);
//     vector<int> dis(n, INF);
//     vector<vector<int>> from(n);
//     auto bfs = [&](int root) {
//         queue<int> q;
//         queue<int> temp;
//         L[root] = 'z';
//         temp.push(root);
//         dis[root] = 0;
//         while (!temp.empty()) {
//             q = temp;
//             temp = queue<int>();
//             set<int> id;
//             while (!q.empty()) {
//                 auto u = q.front();
//                 q.pop();
//                 if (vis[u]) continue;
//                 id.insert(u);
//                 for (auto& [v, c] : adj[u]) {
//                     if (!vis[v] && dis[u] + 1 <= dis[v]) {
//                         dis[v] = dis[u] + 1;
//                         temp.push(v);
//                         if (C[v] > L[u]) {
//                             from[v].clear();
//                             from[v].push_back(u);
//                             C[v] = L[u];
//                             L[v] = c;
//                         }
//                         else if (C[v] == L[u]) {
//                             from[v].push_back(u);
//                             L[v] = min(L[v], c);
//                         }
//                     }
//                 }
//             }
//             for (auto& j : id) vis[j] = true;
//         }
//         };
//     bfs(0);
//     cout << "hel" << endl;
//     deque<int> o;
//     deque<char> s;
//     int j = n - 1;
//     string ans;
//     do {
//         o.push_front(j);
//         s.push_front(L[j]);
//         j = from[j][0];
//     } while (j);
//     if (o.front() != 0) o.push_front(0);
//     cout << o.size() - 1 << endl;
//     // for (auto& c : o) cout << c + 1 << " ";
//     // cout << endl;
//     string f;
//     for (auto& c : s) f += c;
//     cout << " ";
//     string g = brute();
//     if (f != g) {
//         cout << f << " " << g << endl;
//         assert(false);
//     }
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);
//     while (1)
//         solve();
// }



#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, char>>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        char c;
        cin >> u >> v >> c;
        --u;
        --v;
        adj[u].push_back({ v, c });
        adj[v].push_back({ u, c });
    }
    vector<char> L(n, 'z');
    vector<char> C(n, 'z' + 1);
    vector<bool> vis(n);
    vector<int> dis(n, INF);
    vector<vector<int>> from(n);
    auto bfs = [&](int root) {
        queue<int> q;
        queue<int> temp;
        L[root] = 'a';
        temp.push(root);
        dis[root] = 0;
        while (!temp.empty()) {
            q = temp;
            temp = queue<int>();
            set<int> id;
            while (!q.empty()) {
                auto u = q.front();
                q.pop();
                if (vis[u]) continue;
                id.insert(u);
                for (auto& [v, c] : adj[u]) {
                    if (!vis[v] && dis[u] + 1 <= dis[v]) {
                        dis[v] = dis[u] + 1;
                        temp.push(v);
                        if (C[v] > L[u]) {
                            from[v].clear();
                            from[v].push_back(u);
                            C[v] = L[u];
                            L[v] = c;
                        }
                        else if (C[v] == L[u]) {
                            if (c < L[v]) {
                                from[v].clear();
                                from[v].push_back(u);
                                L[v] = c;
                            }
                            else if (c == L[v]) {
                                from[v].push_back(u);
                            }
                            else {}
                        }
                    }
                }
            }
            for (auto& j : id) vis[j] = true;
        }
        };
    bfs(0);
    deque<int> o;
    deque<char> s;
    int j = n - 1;
    string ans;
    do {
        o.push_front(j);
        s.push_front(L[j]);
        j = from[j][0];
    } while (j);
    if (o.front() != 0) o.push_front(0);
    cout << o.size() - 1 << endl;
    for (auto& c : o) cout << c + 1 << " ";
    cout << endl;
    for (auto& c : s) cout << c;
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}

// #include <bits/stdc++.h>
// using namespace std;

// const int INF = 1e9;
// void solve() {
//     int n, m;
//     cin >> n >> m;
//     vector<vector<pair<int, char>>> adj(n);
//     for (int i = 0; i < m; i++) {
//         int u, v;
//         char c;
//         cin >> u >> v >> c;
//         --u;
//         --v;
//         adj[u].push_back({ v, c });
//         adj[v].push_back({ u, c });
//     }
//     vector<char> L(n, 'z');
//     vector<char> C(n, 'z' + 1);
//     vector<bool> vis(n);
//     vector<int> dis(n, INF);
//     vector<vector<int>> from(n);
//     auto bfs = [&](int root) {
//         queue<int> q;
//         queue<int> temp;
//         L[root] = 'a';
//         temp.push(root);
//         dis[root] = 0;
//         while (!temp.empty()) {
//             q = temp;
//             temp = queue<int>();
//             set<int> id;
//             while (!q.empty()) {
//                 auto u = q.front();
//                 cout << "u = " << u << endl;
//                 q.pop();
//                 if (vis[u]) continue;
//                 id.insert(u);
//                 for (auto& [v, c] : adj[u]) {
//                     if (!vis[v] && dis[u] + 1 <= dis[v]) {
//                         cout << u << " >> " << v << endl;
//                         dis[v] = dis[u] + 1;
//                         temp.push(v);
//                         if (C[v] > L[u]) {
//                             from[v].clear();
//                             from[v].push_back(u);
//                             C[v] = L[u];
//                             L[v] = c;
//                         }
//                         else if (C[v] == L[u]) {
//                             if (c < L[v]) {
//                                 from[v].clear();
//                                 from[v].push_back(u);
//                                 L[v] = c;
//                             }
//                             else if (c == L[v]) {
//                                 from[v].push_back(u);
//                             }
//                             else {}
//                         }
//                     }
//                 }
//             }
//             for (auto& j : id) {
//                 vis[j] = true;
//                 cout << j << " -> ";
//             }
//             cout << endl;

//         }
//         };
//     bfs(0);
//     cout << "end" << endl;
//     deque<int> o;
//     deque<char> s;
//     int j = n - 1;
//     string ans;
//     do {
//         o.push_front(j);
//         cout << j << " ";
//         s.push_front(L[j]);
//         j = from[j][0];
//     } while (j);
//     if (o.front() != 0) o.push_front(0);
//     for (auto& c : o) cout << c + 1 << " ";
//     cout << endl;
//     for (auto& c : s) cout << c;
//     cout << endl;
// }

// signed main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);
//     solve();
// }