#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> d(n);
    for (auto& c : d) cin >> c;
    vector<int> a(m);
    for (auto& c : a) cin >> c;
    auto check = [&](int mid) {
        set<int> s = { 0 };
        vector<bool> b(n);
        for (int i = mid; i >= 0; i--) {
            if (!s.count(d[i])) {
                b[i] = true;
                s.insert(d[i]);
            }
        }
        int j = 0;
        for (int i = 0; i <= mid; i++) {
            if (b[i]) {
                int k = a[d[i] - 1];
                while (k && j < i) {
                    if (!b[j]) k--;
                    j++;
                }
                if (k) return false;
            }
        }
        return s.size() == m + 1;
        };
    int L = 0, R = n;
    while (L < R) {
        int mid = (L + R) / 2;
        check(mid) ? R = mid : L = mid + 1;
    }
    cout << (R == n ? -1 : R + 1) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
