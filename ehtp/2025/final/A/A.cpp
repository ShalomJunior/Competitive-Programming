#include<bits/stdc++.h>
using namespace std;

const int N = 10;
void solve() {
    string s;
    int m;
    cin >> s >> m;
    string l, r;
    cin >> l >> r;
    int n = s.length();
    vector<vector<int>> p(N);
    for (int i = 0; i < n; i++) {
        p[s[i] - '0'].push_back(i);
    }
    int k = -1;
    for (int i = 0; i < m && k < n; i++) {
        int j = k;
        for (auto c = l[i]; c <= r[i]; c++) {
            auto& v = p[c - '0'];
            auto it = upper_bound(v.begin(), v.end(), k);
            if (it == v.end()) j = n;
            else {
                j = max(j, *it);
            }
        }
        k = j;
    }
    cout << (k == n ? "YES" : "NO") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}