#include <bits/stdc++.h>
using namespace std;

const int N = 30;
void solve() {
    int n; cin >> n;
    int a[n][n];
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        vector<int> cnt(N);
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            for (int k = 0; k < N; k++) {
                if (a[i][j] & (1 << k)) cnt[k]++;
            }
        }
        for (int k = 0; k < N; k++) {
            if (cnt[k] == n - 1) ans[i] |= (1 << k);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (i != j && (ans[i] | ans[j]) != a[i][j]) {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
    for (auto& c : ans) cout << c << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
