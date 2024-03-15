#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> h(n + 1);
    for (int i = 0; i < n; i++) {
        int c; cin >> c;
        h[c]++;
    }
    vector<long long> b(n + 1);
    b[0] = (h[0] ? 0 : -1);
    auto rem = h;
    set<int> can;
    if (rem[0] > 1) can.insert(0);
    for (int i = 1; i <= n; i++) {
        if (b[i - 1] == -1) {
            b[i] = -1;
            continue;
        }
        if (h[i]) {
            b[i] = b[i - 1];
            if (h[i] > 1) can.insert(i);
        }
        else {
            if (can.empty()) b[i] = -1;
            else {
                auto it = can.lower_bound(i);
                if (it != can.begin()) it--;
                b[i] = b[i - 1] + (i - *it);
                if (--rem[*it] == 1) can.erase(*it);
            }
        }
    }
    for (int i = 0; i <= n; i++) {
        if (b[i] == -1) {
            cout << (i == 0 ? 0 : b[i - 1]) << " ";
            while (++i <= n) cout << -1 << " ";
        }
        else cout << (i ? b[i - 1] : 0LL) + h[i] << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}