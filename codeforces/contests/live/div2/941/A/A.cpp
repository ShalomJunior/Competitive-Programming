#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    map<int, int> cnt;
    int mx = 0;
    for (auto& c : a) {
        cin >> c;
        mx = max(mx, ++cnt[c]);
    }
    cout << (mx < k ? n : k - 1) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
