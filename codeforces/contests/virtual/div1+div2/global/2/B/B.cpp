#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, h;
    cin >> n >> h;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    auto check = [&](int mid) {
        vector<int> p;
        for (int i = 0; i < mid; i++) p.push_back(a[i]);
        sort(p.rbegin(), p.rend());
        int mx = 0;
        for (int i = 0; i + 1 < mid; i += 2) {
            mx += max(p[i], p[i + 1]);
        }
        if (mid & 1) mx += p.back();
        return mx <= h;
        };
    int L = 1, R = n;
    while (L < R) {
        int mid = (L + R) / 2;
        if (check(mid)) {
            if (L == mid) check(R) ? L = R : R = L;
            else L = mid;
        }
        else R = mid - 1;
    }
    cout << L << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}