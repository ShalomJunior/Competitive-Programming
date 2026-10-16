#include<bits/stdc++.h>
using namespace std;

void solve() {
    string t, p;
    cin >> t >> p;
    int n = t.length();
    int m = p.length();
    vector<int> a(n);
    for (auto& c : a) {
        cin >> c;
        c--;
    }
    auto check = [&](int mid) {
        vector<bool> b(n, true);
        for (int i = 0; i < mid; i++) b[a[i]] = false;
        int j = 0;
        for (int i = 0; i < n && j < m; i++) {
            if (b[i] && t[i] == p[j]) {
                j++;
            }
        }
        return j == m;
        };
    int L = 0, R = n;
    while (L < R) {
        int mid = (L + R) / 2;
        if (check(mid)) {
            if (L == mid) check(R) ? L = R : R = L;
            else L = mid;
        }
        else {
            R = mid - 1;
        }
    }
    cout << L << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}