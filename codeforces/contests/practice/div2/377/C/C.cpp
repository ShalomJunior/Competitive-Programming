#include <bits/stdc++.h>
using namespace std;

const int N = 20;
void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    if (q >= n) {
        cout << string(n, '1') << endl;
        return;
    }
    auto check = [&](int mid) {
        int k = q;
        for (int i = mid; i < n; i++) {
            if (k < a[i]) k--;
        }
        return k >= 0;
        };
    int L = 0, R = n;
    while (L < R) {
        int mid = (L + R) / 2;
        check(mid) ? R = mid : L = mid + 1;
    }
    string ans;
    for (int i = 0; i < L; i++) ans += a[i] <= q ? "1" : "0";
    ans += string(n - L, '1');
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
