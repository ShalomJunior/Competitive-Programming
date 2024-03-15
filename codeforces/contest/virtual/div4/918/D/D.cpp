#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; string s;
    cin >> n >> s;
    set<int> in = { 'a', 'e' };
    vector<string> w;
    string t;
    t += s[0];
    for (int i = 1; i < n; i++) {
        if ((in.count(t.back()) && in.count(s[i])) || (!in.count(t.back()) && !in.count(s[i]))) {
            w.push_back(t);
            t = s[i];
        }
        else t += s[i];
    }
    if (!t.empty()) w.push_back(t);
    for (int j = 0; j < w.size(); j++) {
        if (j) cout << '.';
        string str = w[j];
        int m = str.length();
        for (int i = 0; i + 1 < m; i += 2) {
            if (i) cout << '.';
            cout << str[i] << str[i + 1];
        }
        if (m & 1) cout << str[m - 1];
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}