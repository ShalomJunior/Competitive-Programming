#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    int cnt = count(a.begin(), a.end(), 1);
    if (cnt <= 1) {
        cout << "YES" << endl;
        return;
    }
    int i = n;
    int j = 0;
    for (int k = 0; k < n; k++) {
        if (a[k] == 1) {
            i = min(i, k);
            j = max(j, k);
        }
    }
    cout << (j - i < x ? "YES" : "NO") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}