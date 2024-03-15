#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    int M = 0;
    for (auto& c : a) {
        cin >> c;
        M = max(M, c);
    }
    for (int i = 0; i < n; i++) {
        if (a[i] != M) continue;
        int cnt = 0;
        if (i - 1 >= 0 && a[i - 1] < M) cnt++;
        if (i + 1 <= n - 1 && a[i + 1] < M) cnt++;
        if (cnt) {
            cout << i + 1 << endl;
            return;
        }
    }
    cout << -1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}