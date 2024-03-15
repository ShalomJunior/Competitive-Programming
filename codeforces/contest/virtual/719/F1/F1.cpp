#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, t, k;
    cin >> n >> t >> k;
    int L = 1, R = n;
    auto go = [&](int mid) {
        cout << "? " << 1 << " " << mid << endl;
        cout.flush();
        int x; cin >> x;
        return mid - x < k;
        };
    while (L < R) {
        int mid = (L + R) / 2;
        go(mid) ? L = mid + 1 : R = mid;
    }
    cout << "! " << L << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}