#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k; string t;
    cin >> n >> k >> t;
    vector<int> idx;
    for (int i = 0; i < n; i++) {
        if (t[i] == '1') idx.push_back(i);
    }
    vector<int> ans(n), root(n);
    for (int i = 0; i < n; i++) {
        if (root[i]) {
            ans[i] = i;
            continue;
        }
        bool done = false;
        auto f = upper_bound(idx.begin(), idx.end(), i - 1);
        if (f != idx.begin()) {
            --f;
            if (i - *f <= k) {
                ans[i] = 1;
                root[*f] = 1;
                done = true;
            }
        }
        auto s = lower_bound(idx.begin(), idx.end(), i + 1);
        if (s != idx.end() && *s - i <= k) {
            ans[i] = 1;
            root[*s] = 1;
            done = true;
        }
        if (!done && t[i] == '1') {
            ans[i] = root[i] = 1;
        }
    }
    int cost = 0;
    for (int i = 0; i < n; i++) {
        if ((ans[i] && root[i]) || !ans[i]) {
            cost += i + 1;
        }
    }
    cout << cost << endl;
}

int  main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}