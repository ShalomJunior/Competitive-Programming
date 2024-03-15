#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    vector<int> pre_odd(n), pre_even(n);
    for (int i = 0, e = 0, o = 0; i < n; i++) {
        i & 1 ? o += a[i] : e += a[i];
        pre_odd[i] = o;
        pre_even[i] = e;
    }
    vector<int> suf_odd(n), suf_even(n);
    for (int i = n - 1, e = 0, o = 0; i >= 0; i--) {
        i & 1 ? o += a[i] : e += a[i];
        suf_odd[i] = o;
        suf_even[i] = e;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int o = i ? pre_odd[i - 1] : 0;
        int e = i ? pre_even[i - 1] : 0;
        if (i + 1 < n) {
            o += suf_even[i + 1];
            e += suf_odd[i + 1];
        }
        if (o == e) ans++;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}