
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    multiset<int> a, b;
    for (int i = 0; i < n; i++) {
        int c; cin >> c;
        a.insert(c);
    }
    for (int i = 0; i < n; i++) {
        int c; cin >> c;
        b.insert(c);
    }
    while (k--) {
        int x = *a.begin();
        int y = *prev(b.end());
        if (x >= y) break;
        a.erase(a.begin());
        b.erase(prev(b.end()));
        a.insert(y);
        b.insert(x);
    }
    cout << accumulate(a.begin(), a.end(), 0) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}