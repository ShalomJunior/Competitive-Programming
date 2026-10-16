#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    int ans = 1;
    set<int> in, out;
    out.insert(a[0]);
    for (int i = 1; i < n; i++) {
        out.erase(a[i]);
        in.insert(a[i]);
        if (out.empty()) {
            out = in;
            in.clear();
            ans++;
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}