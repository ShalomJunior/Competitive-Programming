#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> b(m);
    for (auto& c : b) cin >> c;
    sort(b.begin(), b.end());
    while (q--) {
        int x;
        cin >> x;
        auto it = upper_bound(b.begin(), b.end(), x);
        if (it == b.begin()) {
            cout << *it - 1;
        }
        else if (it == b.end()) {
            cout << n - *(--it);
        }
        else {
            int r = *it;
            --it;
            int l = *it;
            cout << (r - l) / 2;
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}