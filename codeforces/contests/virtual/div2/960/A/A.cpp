#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    map<int, int> h;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        h[x]++;
    }
    for (auto& [k, v] : h) {
        if (v & 1) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}