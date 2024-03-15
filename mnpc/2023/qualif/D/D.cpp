#include <bits/stdc++.h>
using namespace std;

vector<int> kmp_table(string p) {
    int m = p.length();
    vector<int> ans(m);
    int k = 0;
    for (int q = 1; q < m; ++q) {
        while (k > 0 && p[k] != p[q]) {
            k = ans[k - 1];
        }
        if (p[q] == p[k])k++;
        ans[q] = k;
    }
    return ans;
}

vector<int> kmp(string s, string p) {
    vector<int> ans;
    int n = s.length(), m = p.length();
    auto table = kmp_table(p);
    int k = 0;
    for (int i = 0; i < n; i++) {
        while (k > 0 && s[i] != p[k])k = table[k - 1];
        if (s[i] == p[k])k++;
        if (k == m) {
            ans.push_back(i - m + 1);
            k = table[k - 1];
        }
    }
    return ans;
}

void solve() {
    string s; cin >> s;
    int q; cin >> q;
    while (q--) {
        int t; cin >> t;
        if (t & 1) {
            string p; cin >> p;
            auto tb = kmp(s, p);
            cout << ((tb.size()) ? tb[0] + 1 : -1) << endl;
        }
        else {
            int i; char c; cin >> i >> c;
            s[i - 1] = c;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}