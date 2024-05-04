#include <bits/stdc++.h>
using namespace std;

const int N = 8005;
void solve() {
    int n; cin >> n;
    vector<int> a(n), pre(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pre[i] = a[i] + (i ? pre[i - 1] : 0);
    }
    vector<int> can(N);
    for (int i = 0; i < n; i++) {
        if (i && pre[i] < N) can[pre[i]] = 1;
        for (int j = 0; j < i - 1; j++) {
            int v = pre[i] - pre[j];
            if (v < N) can[v] = 1;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (can[a[i]]) ans++;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}