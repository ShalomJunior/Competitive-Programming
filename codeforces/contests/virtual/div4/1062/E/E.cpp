#include <bits/stdc++.h>
#define int long long
using namespace std;


void merge(vector <pair<int, int>>& x) {
    int n = x.size();
    if (n == 0) return;
    sort(x.begin(), x.end());
    vector<pair<int, int>> temp;
    int l = x[0].first;
    int r = x[0].second;
    for (int i = 1; i < n; i++) {
        if (x[i].first > r) {
            temp.push_back({ l, r });
            l = x[i].first;
            r = x[i].second;
        }
        else {
            r = max(r, x[i].second);
        }
    }
    temp.push_back({ l, r });
    x = temp;
}

void solve() {
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> p(n);
    for (auto& c : p) cin >> c;
    vector<int> tels(k);
    iota(tels.begin(), tels.end(), 0);
    auto go = [&](int mid) {
        if (mid == 0) return true;
        vector<pair<int, int>> in;
        for (auto& c : p) {
            in.push_back({ max(c - mid + 1, 0LL), min(c + mid - 1, x) });
        }
        merge(in);
        in.push_back({ x + 1, x + 1 });
        int last = -1;
        vector<int> ntels;
        for (auto& [l, r] : in) {
            for (int j = last + 1; j < l && ntels.size() < k; j++) {
                ntels.push_back(j);
            }
            last = r;
        }
        if (ntels.size() >= k) {
            tels = ntels;
            return true;
        }
        return false;
        };
    int L = 0, R = x + 1;
    while (L < R) {
        int mid = (L + R) / 2;
        if (go(mid)) {
            if (L == mid) go(R) ? L = R : R = L;
            else L = mid;
        }
        else {
            R = mid - 1;
        }
    }
    for (auto& c : tels) cout << c << " ";
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}