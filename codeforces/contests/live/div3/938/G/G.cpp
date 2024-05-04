#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

void solve() {
    int n, m;
    cin >> n >> m;
    auto id = [&](int i, int j) {
        return i * m + j;
        };
    vector<vector<int>> a(n, vector<int>(m));
    unordered_map<int, vector<int>> all;
    //vector<pair<int, int>> all;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x; cin >> x;
            a[i][j] = x;
            for (int k = 1; k * k <= x; k++) {

                if (x % k == 0) {
                    all[k].push_back(id(i, j));
                    //all.push_back({ k, id(i, j) });
                    if (x / k != k) {
                        all[x / k].push_back(id(i, j));
                        //all.push_back({ x / k, id(i, j) });
                    }
                }
            }
        }
    }
    int ans = 1;
    for (auto& [j, vec] : all) {
        int z = vec.size();
        if (z < n + m - 1 || j == 1) continue;
        set<int> s(vec.begin(), vec.end());
        auto bfs = [&](int root) {
            queue<int> q;
            q.push(root);
            while (!q.empty()) {
                int u = q.front();
                if (u == id(0, 0)) return true;
                int l = u / m;
                int r = u % m;
                q.pop();
                if (s.count(id(l - 1, r))) {
                    q.push(id(l - 1, r));
                }
                if (s.count(id(l, r - 1))) {
                    q.push(id(l, r - 1));
                }
            }
            return false;
            };
        if (s.count(id(n - 1, m - 1)) && bfs(id(n - 1, m - 1))) {
            ans = max(ans, j);
        }
    }
    //sort(all.begin(), all.end());
    // int z = all.size();
    // int ans = 1;
    // int i = 0;
    // while (i < z) {
    //     unordered_set<int> s;
    //     int j = i;
    //     while (j < z && all[j].first == all[i].first) {
    //         //s.insert(all[j].second);
    //         j++;
    //     }
    //     int sz = s.size();
    //     i = j;
    // }
    //for (auto& [j, hash] :) {
        // int z = d[j].size();
        // if (z < n + m - 1 || j == 1) continue;
        // auto bfs = [&](int root) {
        //     queue<int> q;
        //     q.push(root);
        //     while (!q.empty()) {
        //         int u = q.front();
        //         if (u == id(0, 0)) return true;
        //         int l = u / m;
        //         int r = u % m;
        //         q.pop();
        //         if (d[j].count(id(l - 1, r))) {
        //             q.push(id(l - 1, r));
        //         }
        //         if (d[j].count(id(l, r - 1))) {
        //             q.push(id(l, r - 1));
        //         }
        //     }
        //     return false;
        //     };
        // if (d[j].count(id(n - 1, m - 1)) && bfs(id(n - 1, m - 1))) {
        //     ans = max(ans, j);
        // }
    //}
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // int T = 25;
    // cout << T << endl;
    // while (T--) {
    //     int P = 100;
    //     cout << P << " " << P << endl;
    //     for (int i = 0; i < P; i++) {
    //         for (int j = 0; j < P; j++) {
    //             cout << rand() % 1000000 << " ";
    //         }
    //         cout << endl;
    //     }
    // }
    int t; cin >> t;
    while (t--)solve();
}

/*
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
void solve() {
    int n, m;
    cin >> n >> m;
    auto id = [&](int i, int j) {
        return i * m + j;
        };
    vector<vector<int>> a(n, vector<int>(m));
    unordered_map<int, set<int>> d;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x; cin >> x;
            a[i][j] = x;
            for (int k = 1; k * k <= x; k++) {
                if (x % k == 0) {
                    d[k].insert(id(i, j));
                    if (x / k != k) {
                        d[x / k].insert(id(i, j));
                    }
                }
            }
        }
    }
    int ans = 1;
    //for (auto& [j, hash] :) {
        // int z = d[j].size();
        // if (z < n + m - 1 || j == 1) continue;
        // auto bfs = [&](int root) {
        //     queue<int> q;
        //     q.push(root);
        //     while (!q.empty()) {
        //         int u = q.front();
        //         if (u == id(0, 0)) return true;
        //         int l = u / m;
        //         int r = u % m;
        //         q.pop();
        //         if (d[j].count(id(l - 1, r))) {
        //             q.push(id(l - 1, r));
        //         }
        //         if (d[j].count(id(l, r - 1))) {
        //             q.push(id(l, r - 1));
        //         }
        //     }
        //     return false;
        //     };
        // if (d[j].count(id(n - 1, m - 1)) && bfs(id(n - 1, m - 1))) {
        //     ans = max(ans, j);
        // }
    //}
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // int T = 20;
    // cout << T << endl;
    // while (T--) {
    //     int P = 100;
    //     cout << P << " " << P << endl;
    //     for (int i = 0; i < P; i++) {
    //         for (int j = 0; j < P; j++) {
    //             cout << rand() % 1000000 << " ";
    //         }
    //         cout << endl;
    //     }
    // }
    int t; cin >> t;
    while (t--)solve();
}

*/