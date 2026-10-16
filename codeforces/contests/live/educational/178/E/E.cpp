#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    vector<vector<int>> p(k);
    for (int i = 0; i < n; i++) {
        p[s[i] - 'a'].push_back(i);
    }
    set<int> let;
    vector<int> cnt(n + 1);
    for (int i = n - 1; i >= 0; i--) {
        let.insert(s[i]);
        if ((int)let.size() == k) {
            cnt[i] = cnt[i + 1] + 1;
            let.clear();
        }
        else {
            cnt[i] = cnt[i + 1];
        }
    }
    auto get = [&](string& t) {
        int m = t.length();
        int j = -1;
        for (int i = 0; i < m; i++) {
            auto& v = p[t[i] - 'a'];
            auto it = upper_bound(v.begin(), v.end(), j);
            if (it == v.end()) return n;
            j = *it;
        }
        return j;
        };
    int q;
    cin >> q;
    while (q--) {
        string t;
        cin >> t;
        int j = get(t);
        if (j == n) {
            cout << 0;
        }
        else {
            cout << cnt[j + 1] + 1;
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
