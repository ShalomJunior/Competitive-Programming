#include <bits/stdc++.h>
using namespace std;

struct info {
    string a, b, c;
    bool operator<(const info& other) const {
        if (a != other.a) return a < other.a;
        if (b != other.b) return b < other.b;
        return c < other.c;
    }
};

pair<string, string> read() {
    string line;
    cin >> line;
    int m = line.size();
    string s, t;
    for (int i = 0; i < m; i++) {
        if (line[i] == ',') {
            t = line.substr(i + 1, m - (i + 1));
            break;
        }
        s += line[i];
    }
    return { s, t };
}

void solve() {
    int n; cin >> n;
    map<string, string> f;
    for (int i = 0; i < n; i++) {
        auto [s, t] = read();
        f[s] = t;
    }
    int m; cin >> m;
    map<string, string> g;
    for (int i = 0; i < m; i++) {
        auto [s, t] = read();
        g[t] = s;
    }
    vector<info> ans;
    for (auto& [s, t] : f) {
        if (g.count(s)) {
            ans.push_back({ s, t, g[s] });
        }
    }
    sort(ans.begin(), ans.end());
    for (auto& [a, b, c] : ans) {
        cout << a << "," << b << "," << c << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
