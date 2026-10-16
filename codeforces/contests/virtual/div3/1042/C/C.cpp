#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    map<int, int> S;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        int u = x % k;
        int v = k - u;
        S[min(u, v)]++;
    }
    map<int, int> T;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        int u = x % k;
        int v = k - u;
        T[min(u, v)]++;
    }
    for (auto& [k, v] : S) {
        if (T[k] != v) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}