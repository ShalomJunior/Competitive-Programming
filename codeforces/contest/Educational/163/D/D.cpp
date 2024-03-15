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

vector<vector<int>> kmp(string s, string p) {
    int n = s.length(), m = p.length();
    vector<vector<int>> ans(m + 1);
    auto table = kmp_table(p);
    int k = 0;
    for (int i = 0; i < n; i++) {
        while (k > 0 && s[i] != p[k])k = table[k - 1];
        if (s[i] == p[k])k++;
        for (int j = 1; j <= k; j++) {
            ans[j].push_back(i - k + 1);
        }
    }
    return ans;
}

void solve() {
    int n;
    string s;
    cin >> n >> s;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string a = "madmamam";
    string b = "mama";
    auto f = kmp(a, b);
    for (int i = 1; i < 5; i++) {
        for (auto& c : f[i])cout << c << " ";
        cout << endl;
    }
    cout << endl;
    int t; cin >> t;
    while (t--) solve();
}
