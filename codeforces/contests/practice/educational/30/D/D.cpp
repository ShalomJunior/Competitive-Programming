#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    if (k % 2 == 0 || 2 * n - 1 < k) {
        cout << -1 << endl;
        return;
    }
    vector<int> p(n);
    iota(p.begin(), p.end(), 1);
    int bad = 1;
    function<void(int, int)>  go = [&](int l, int r) {
        if (bad == k) return;
        int mid = (l + r) / 2;
        int left = mid - l;
        int right = r - mid;
        if (left && right) {
            swap(p[mid - 1], p[mid]);
            bad += 2;
        }
        if (left > 1) go(l, mid);
        if (right > 1) go(mid, r);
        };
    go(0, n);
    for (auto& c : p) cout << c << " ";
    cout << endl;
    assert(bad == k);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}