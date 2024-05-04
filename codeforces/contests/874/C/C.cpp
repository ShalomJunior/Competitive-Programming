#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    set<int> even, odd;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        (a[i] & 1) ? odd.insert(a[i]) : even.insert(a[i]);
    }

    bool good = true;
    for (int i = 0; i < n; i++) {
        if (a[i] & 1) {
            odd.erase(a[i]);
            good &= (odd.upper_bound(a[i]) != odd.begin());
            odd.insert(a[i]);
        }
    }

    if (good) { cout << "YES" << endl; return; }

    good = true;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0)
            good &= (odd.upper_bound(a[i]) != odd.begin());
    }

    cout << ((good) ? "YES" : "NO") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}