#include <bits/stdc++.h>
using namespace std;

const int N = 26;

class dsu {
public:
    vector<int> parents;
    vector<int> sizes;
    dsu(int n) {
        parents.resize(n);
        iota(parents.begin(), parents.end(), 0);
        sizes.resize(n, 1);
    }
    int root(int u) {
        return parents[u] == u ? u : parents[u] = root(parents[u]);
    }
    bool join(int u, int v) {
        int a = root(u);
        int b = root(v);
        if (a == b) return 0;
        if (sizes[a] > sizes[b]) swap(a, b);
        parents[a] = b;
        sizes[b] += sizes[a];
        return 1;
    }
};

void solve() {
    int n;
    string s;
    cin >> n >> s;
    vector<int> p(N, -1);
    dsu ds(N);
    set<int> lets;
    for (int i = 0; i < N; i++) lets.insert(i);
    for (auto& c : s) {
        int j = c - 'a';
        if (p[j] == -1) {
            for (auto it = lets.begin(); it != lets.end(); it++) {
                if (p[*it] != j) {
                    int x = ds.root(j);
                    int y = ds.root(*it);
                    if (x == y && ds.sizes[x] != N) continue;
                    p[j] = *it;
                    break;
                }
            }
            ds.join(j, p[j]);
            lets.erase(p[j]);
        }
        cout << (char)('a' + p[j]);
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}