#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> p(n);
    for (auto& c : p) cin >> c;
    vector<int> ans(n);
    function<void(int, int, int)> go = [&](int id, int l, int r) {
        int j = l;
        for (int i = l; i <= r; i++) {
            if (p[i] > p[j]) j = i;
        }
        ans[j] = id;
        if (j != l) go(id + 1, l, j - 1);
        if (j != r) go(id + 1, j + 1, r);
        };
    go(0, 0, n - 1);
    for (auto& c : ans) cout << c << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}