#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<pair<string, string>> a(n);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int m = s.length();
        int j = 0;
        while (j < s.size() && s[j] != '-') j++;
        a[i] = { s.substr(0, j), s.substr(j + 1, m - j) };
    }
    sort(a.begin(), a.end(), [&](const pair<string, string>& x, const pair<string, string>& y) {
        if (x.second != y.second) return x.second < y.second;
        return x.first < y.first;
        }
    );
    for (auto& p : a) {
        cout << p.first << "-" << p.second << "\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}