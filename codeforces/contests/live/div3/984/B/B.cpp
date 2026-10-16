#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    map<int, int> h;
    for (int i = 0; i < k; i++) {
        int b, c;
        cin >> b >> c;
        h[b] += c;
    }
    deque<int> a;
    for (auto& [k, v] : h) a.push_back(v);
    sort(a.begin(), a.end());
    int ans = 0;
    while (!a.empty() && n) {
        ans += a.back();
        a.pop_back();
        n--;
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
