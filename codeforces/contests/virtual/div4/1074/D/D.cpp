#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, m, h;
    cin >> n >> m >> h;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    vector<int> up = a;
    set<int> in;
    for (int i = 0; i < m; i++) {
        int b, c;
        cin >> b >> c;
        --b;
        if (in.count(b)) {
            up[b] += c;
        }
        else {
            up[b] = a[b] + c;
            in.insert(b);
        }
        if (up[b] > h) in.clear();
    }
    for (int i = 0; i < n; i++) {
        cout << (in.count(i) ? up[i] : a[i]) << " ";
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}