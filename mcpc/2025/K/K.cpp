#include<bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    int max_nodes = 2 * n + 10;
    vector<int> len(max_nodes), link(max_nodes);
    vector<array<int, 26>> next(max_nodes);
    int last = 0;
    int sz = 1;
    len[0] = 0;
    link[0] = -1;
    for (int i = 0; i < 26; i++) {
        next[0][i] = 0;
    }

    for (char c : s) {
        int cur = sz++;
        len[cur] = len[last] + 1;
        for (int i = 0; i < 26; i++) {
            next[cur][i] = 0;
        }
        int p = last;
        while (p != -1 && !next[p][c - 'a']) {
            next[p][c - 'a'] = cur;
            p = link[p];
        }
        if (p == -1) {
            link[cur] = 0;
        }
        else {
            int q = next[p][c - 'a'];
            if (len[p] + 1 == len[q]) {
                link[cur] = q;
            }
            else {
                int clone = sz++;
                len[clone] = len[p] + 1;
                link[clone] = link[q];
                next[clone] = next[q];
                while (p != -1 && next[p][c - 'a'] == q) {
                    next[p][c - 'a'] = clone;
                    p = link[p];
                }
                link[q] = clone;
                link[cur] = clone;
            }
        }
        last = cur;
    }

    vector<int> g(sz, 0);
    vector<int> indices(sz);
    iota(indices.begin(), indices.end(), 0);
    sort(indices.begin(), indices.end(), [&](int i, int j) {
        return len[i] > len[j];
        });

    for (int i : indices) {
        bool seen[27] = { false };
        for (int c = 0; c < 26; c++) {
            if (next[i][c] != 0) {
                int j = next[i][c];
                if (g[j] < 27) {
                    seen[g[j]] = true;
                }
            }
        }
        int mex = 0;
        while (mex < 27 && seen[mex]) {
            mex++;
        }
        g[i] = mex;
    }
    if (g[0] != 0) {
        cout << "Gamal\n";
    }
    else {
        cout << "Folka\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}