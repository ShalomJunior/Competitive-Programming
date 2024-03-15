#include <bits/stdc++.h>
using namespace std;

const int N = 50;
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    vector<string> ans(n + 1);
    ans[0] = string(N, 'a');
    for (int i = 0; i < n; i++) {
        ans[i + 1] = ans[i].substr(0, a[i]);
        char c = 'a';
        int j = a[i];
        while (j < ans[i].size() && c == ans[i][j])c++;
        while (ans[i + 1].size() < N)ans[i + 1] += c;
    }
    for (auto& s : ans) cout << s << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}