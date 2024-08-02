#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> s(n);
    for (int i = 0; i < m; i++) s[i]--;
    for (int i = k - 1; i < n; i++) s[i]++;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] > 0) {
            cout << i + 1 << " ";
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == 0) {
            cout << i + 1 << " ";
        }
    }
    for (int i = 0; i < n; i++) {
        if (s[i] < 0) {
            cout << i + 1 << " ";
        }
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}