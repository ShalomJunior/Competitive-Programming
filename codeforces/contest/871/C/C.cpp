#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int f(vector<int>& v) { return *min_element(v.begin(), v.end()); }

void solve() {
    int n; cin >> n;
    unordered_map<string, vector<int>> m;
    for (int i = 0; i < n; i++) {
        int n; string s;
        cin >> n >> s;
        m[s].push_back(n);
    }

    int ans = INF;
    if (m["11"].size() > 0) {
        ans = min(ans, f(m["11"]));
    }
    if (m["01"].size() > 0 && m["10"].size() > 0) {
        ans = min(ans, f(m["01"]) + f(m["10"]));
    }
    cout << ((ans == INF) ? -1 : ans) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}