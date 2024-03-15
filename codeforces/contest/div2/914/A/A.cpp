#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b; cin >> a >> b;
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    vector<pair<int, int>> pos = { {a, b}, {b, a} };
    vector<int> m = { -1, 1 };
    map<pair<int, int>, int> cnt1, cnt2;
    for (auto& p : pos) {
        for (int i : m) {
            for (int j : m) {
                cnt1[{x1 + i * p.first, y1 + j * p.second}]++;
                cnt2[{x2 + i * p.first, y2 + j * p.second}]++;
            }
        }
    }
    int ans = 0;
    for (auto& [k, v] : cnt1) {
        if (cnt2.count(k)) ans++;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
