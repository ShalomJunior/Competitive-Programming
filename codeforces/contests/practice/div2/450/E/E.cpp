#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> cnt(n + 1);
    for (int i = 1; i < n; i++) {
        for (int j = i; j <= n; j += i) cnt[j]++;
    }
    for (int i = 0; i <= n; i++) {
        if (cnt[i] > m) cout << i << " ";
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}