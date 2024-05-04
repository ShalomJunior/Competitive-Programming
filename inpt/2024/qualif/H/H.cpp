#include <bits/stdc++.h>
using namespace std;

const int D = 24 * 60;
pair<int, int> read() {
    string s; cin >> s;
    int n = s.length();
    auto get = [](string p) {
        int z = p.size();
        int j = 0;
        while (p[j] != ':') j++;
        int h = stoi(p.substr(0, j));
        int m = stoi(p.substr(j + 1, z - (j + 1)));
        return h * 60 + m;
        };
    int j = 0;
    while (s[j] != '-') j++;
    auto res = make_pair(get(s.substr(0, j)), get(s.substr(j + 1, n - (j + 1))));
    assert(res.first <= res.second);
    return res;
}

void merge(vector<pair<int, int>>& x) {
    int n = x.size();
    sort(x.begin(), x.end());
    vector<pair<int, int>> temp;
    int l = x[0].first;
    int r = x[0].second;
    for (int i = 1; i < n; i++) {
        if (x[i].first > r) {
            temp.push_back({ l, r });
            l = x[i].first;
            r = x[i].second;
        }
        else {
            r = max(r, x[i].second);
        }
    }
    temp.push_back({ l, r });
    x = temp;
}

void solve() {
    int a; cin >> a;
    vector<pair<int, int>> x;
    for (int i = 0; i < a; i++) {
        x.push_back(read());
    }
    merge(x);
    int m; cin >> m;
    vector<pair<int, int>> y;
    for (int i = 0; i < m; i++) {
        y.push_back(read());
    }
    merge(y);
    int Z = D;
    vector<int> f(Z);
    for (auto& [l, r] : x) {
        for (int i = l; i <= r; i++) {
            assert(f[i] == 0);
            f[i]++;
        }
    }
    vector<int> g(Z);
    for (auto& [l, r] : y) {
        for (int i = l; i <= r; i++) {
            assert(g[i] == 0);
            g[i]++;
        }
    }
    for (int i = 0; i < Z; i++) {
        int s = 0;
        for (int j = i; j < Z && f[j] && g[j]; j++) s++;
        if (s >= 30) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}