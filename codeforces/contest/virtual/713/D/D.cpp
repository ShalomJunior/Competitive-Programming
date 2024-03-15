#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n + 2);
    map<int, int> h;
    for (auto& c : a) cin >> c, h[c]++;
    sort(a.begin(), a.end());
    long long sum = accumulate(a.begin(), a.end(), 0LL);
    for (int i = 0; i < n + 2; i++) {
        long long tot = sum - a[i];
        if (tot & 1) continue;
        int cnt = 1 + (a[i] == tot / 2);
        if (h[tot / 2] < cnt) continue;
        int z = 0;
        for (int j = 0; z < n && j < n + 2; j++) {
            if (i == j || (n > 1 && a[j] == tot / 2)) continue;
            cout << a[j] << " ";
            z++;
        }
        cout << endl;
        return;
    }
    cout << -1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}