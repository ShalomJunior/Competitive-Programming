#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
    }
    string s;
    cin >> s;
    vector<int> ans(n);
    for (int i = 0; i < n; i++) ans[i] = s[i] == '0' ? 1 : 0;
    vector<bool> vis(n, -1);
    function<void(int) go = [&](int r) {

        };
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}