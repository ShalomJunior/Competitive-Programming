#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 1; i <= n; i++) cin >> a[i];
    int q;
    cin >> q;
    vector<pair<int, int>> Q(q);
    for (int i = 0; i < n; i++) {
        cin >> Q[i].first >> Q[i].second;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
