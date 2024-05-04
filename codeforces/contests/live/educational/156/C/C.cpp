#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s; long long k;
    cin >> s >> k;
    int n = s.size();
    vector<int> order;
    set<int> id;
    for (int i = 0; i < n; i++) id.insert(i);
    for (int i = 0; i < n - 1; i++) {
        if (s[i] <= s[i + 1]) continue;
        vector<int> del;
        for (auto it = id.lower_bound(i); s[*it] > s[i + 1]; it--) {
            del.push_back(*it);
            if (it == id.begin()) break;
        }
        for (auto& c : del) {
            order.push_back(c);
            id.erase(c);
        }
    }
    while (!id.empty()) {
        order.push_back(*prev(id.end()));
        id.erase(prev(id.end()));
    }
    int L = 0, R = n - 1;
    auto go = [&](int mid) {
        long long ans = 1LL * mid * (2 * n - mid + 1) / 2;
        return ans < k;
        };
    while (L < R) {
        int mid = (L + R) / 2;
        if (go(mid)) {
            if (L == mid) go(R) ? L = R : R = L;
            else L = mid;
        }
        else R = mid - 1;
    }
    int r = k - (1LL * L * (2 * n - L + 1)) / 2;
    set<int> ban;
    for (int i = 0; i < L; i++) ban.insert(order[i]);
    for (int i = 0, j = 0; i < n; i++) {
        if (ban.count(i)) continue;
        j++;
        if (j == r) {
            cout << s[i];
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
