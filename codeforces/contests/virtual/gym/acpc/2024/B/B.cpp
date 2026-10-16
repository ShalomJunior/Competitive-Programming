#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    map<int, int> h;
    vector<pair<int, int>> p(n);
    for (auto& [l, r] : p) {
        cin >> l >> r;
        h[l]++;
        if (l != r) h[r]++;
    }
    bool ans = false;
    function<void(int, int, int)> go = [&](int left, int right, int j) {
        if (ans) return;
        if (j == n) {
            if (h[left] < 7 || h[right] < 7) ans = true;
            return;
        }
        auto [l, r] = p[j];
        if (left == r) go(l, right, j + 1);
        if (right == l) go(left, r, j + 1);
        if (left == l) go(r, right, j + 1);
        if (right == r) go(left, l, j + 1);
        };
    go(p[0].first, p[0].second, 1);
    cout << (ans ? "Yes" : "No") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}