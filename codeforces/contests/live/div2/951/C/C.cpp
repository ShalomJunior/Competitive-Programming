#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e9;
void solve() {
    int n;
    cin >> n;
    vector<int> k(n);
    for (auto& c : k) cin >> c;
    vector<int> bet(n);
    auto go = [&](int mid) {
        for (int i = 0; i < n; i++) {
            int d = mid / k[i];
            while (d * k[i] <= mid) d++;
            bet[i] = d;
        }
        int all = accumulate(bet.begin(), bet.end(), 0LL);
        return all <= mid;
        };
    int L = 0, R = INF;
    while (L <= R) {
        int mid = (L + R) / 2;
        if (go(mid)) {
            for (auto& c : bet) cout << c << " ";
            cout << endl;
            return;
        }
        else L = mid + 1;
    }
    cout << -1 << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}

