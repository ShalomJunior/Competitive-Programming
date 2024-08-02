#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e18;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> seg(m);
    set<int> starts, ends;
    vector<int> all;
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        starts.insert(l);
        ends.insert(r);
        all.push_back(l);
        all.push_back(r);
    }
    sort(all.begin(), all.end());
    all.resize(unique(all.begin(), all.end()) - all.begin());
    auto check = [&](int mid) {
        cerr << "mid = " << mid << endl;
        int cnt = 0;
        int last = -INF;
        while (cnt < n) {
            auto it = upper_bound(all.begin(), all.end(), last + mid);
            int pos = it - all.begin();
            if (pos == m) return false;
            if (ends.count(*it)) {
                last += mid;
            }
            else {
                last = *it;
            }
            cnt++;
        }
        return true;
        };
    int L = 0, R = 3e18;
    while (L < R) {
        int mid = (L + R) / 2;
        if (check(mid)) {
            if (L == R) check(R) ? L = R : R = L;
            else L = R;
        }
        else R = mid - 1;
    }
    cerr << "ans" << endl;
    cout << L << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}