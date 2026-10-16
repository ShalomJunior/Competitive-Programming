#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    auto go = [&](int mid) {
        int cnt = 0;
        vector<int> x(mid);
        for (int i = 0, m = 0; i < n; i++) {
            if (a[i] < mid && x[a[i]] < cnt + 1) {
                x[a[i]] = cnt + 1;
                m++;
            }
            if (m == mid) {
                cnt++;
                m = 0;
            }
        }
        return cnt >= k;
        };
    int L = 0, R = n;
    while (L < R) {
        int mid = (L + R) / 2;
        if (go(mid)) {
            if (L == mid) go(R) ? L = R : R = L;
            else L = mid;
        }
        else R = mid - 1;
    }
    cout << L << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}