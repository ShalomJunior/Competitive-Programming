#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> v(n);
    for (auto& i : v) cin >> i;

    int sm = 0;
    for (int i = 0; i < n;) {
        if (v[i] > 0) {
            sm += v[i];
            continue;
        }

        int cnt = 0, mx = INT_MIN;
        while (v[i + cnt] <= 0) {
            cnt++; mx = max(mx, v[i + cnt]);
        }

        if (cnt % 2 == 0) {
            sm -= accumulate(v.begin() + i, v.begin() + i + cnt, 0);
            i += cnt + 1;
        }
        else {
            if (v[i - 1] > -mn)
        }

    }

    int mx = accumulate(v.begin(), v.end(), 0);
    cout << mx << endl;
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}