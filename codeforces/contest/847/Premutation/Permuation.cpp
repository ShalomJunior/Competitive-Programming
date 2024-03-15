#include <bits/stdc++.h>

using namespace std;

pair<int, int>mx(unordered_map<int, int>& mp) {
    pair<int, int> ans = { INT_MIN, INT_MIN };
    for (auto [k, v] : mp) {
        if (v > ans.second) {
            ans.first = k;
            ans.second = v;
        }
    }
    return ans;
}

void solve() {
    int n; cin >> n;
    vector<unordered_map<int, int>> v(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            int k; cin >> k;
            v[j][k]++;
        }
    }

    vector<bool> ranked(n + 1, false);
    stringstream ans;
    auto p = mx(v[0]);
    ans << p.first << " "; ranked[p.first] = true;

    for (auto& mp : v) {
        for (auto [k, w] : mp) {
            if (!ranked[k]) {
                ans << k << " "; ranked[k] = true;
            }
        }
    }

    cout << ans.str() << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}