#include <bits/stdc++.h>
#define int long long
using namespace std;

void merge(vector<pair<int, int>>& x) {
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
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (auto& c : a) cin >> c;
    for (auto& c : b) cin >> c;
    a.resize(unique(a.begin(), a.end()) - a.begin());
    n = a.size();
    auto check = [&](int r) {
        vector<pair<int, int>> inter;
        for (auto& c : b) inter.push_back({ c - r, c + r });
        merge(inter);
        if (a[0] < inter[0].first || a.back() > inter.back().second) return false;
        for (int i = 1; i < inter.size(); i++) {
            int j = upper_bound(a.begin(), a.end(), inter[i - 1].second) - a.begin();
            if (j != n && a[j] < inter[i].first) return false;
        }
        return true;
        };
    int L = 0, R = 1e10;
    while (L < R) {
        int mid = (L + R) / 2;
        check(mid) ? R = mid : L = mid + 1;
    }
    cout << R << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
