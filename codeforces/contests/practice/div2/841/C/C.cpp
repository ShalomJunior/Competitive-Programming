#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> x(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        x[i] = x[i - 1] ^ a[i];
    }
    long long tot = 1LL * n * (n + 1) / 2;
    for (int j = 0; j * j <= 2 * n; j++) {
        int r = j * j;
        vector<int> cnt(4 * n);
        for (int i = 0; i <= n; i++) {
            tot -= cnt[x[i] ^ r];
            cnt[x[i]]++;
        }
    }
    cout << tot << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
