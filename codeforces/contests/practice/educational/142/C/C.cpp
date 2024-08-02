#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c, c--;
    auto check = [&](int mid) {
        vector<int> r;
        for (int i = 0; i < n; i++) {
            if (a[i] < mid || a[i] >= n - mid) {}
            else {
                r.push_back(a[i]);
            }
        }
        return is_sorted(r.begin(), r.end());
        };
    int L = 0, R = n / 2;
    while (L < R) {
        int mid = (L + R) / 2;
        check(mid) ? R = mid : L = mid + 1;
    }
    cout << R << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}