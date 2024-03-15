#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    multiset<int> ms;
    for (auto& c : a) cin >> c;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        ms.insert(x);
    }
    for (int i = 0; i < n; i++) {
        auto it = ms.lower_bound(n - a[i]);
        if (it == ms.end()) {
            b[i] = *ms.begin();
            ms.erase(ms.begin());
        }
        else {
            b[i] = *it;
            ms.erase(it);
        }
    }
    for (int i = 0; i < n; i++) {
        cout << (a[i] + b[i]) % n << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}