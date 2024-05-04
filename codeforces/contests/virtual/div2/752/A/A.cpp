#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    long long m = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > i + 1 + m) {
            m += a[i] - (i + 1 + m);
        }
    }
    cout << m << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}