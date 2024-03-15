#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    map<int, int> h;
    for (int i = 0; i < (n * (n - 1)) / 2; i++) {
        int a; cin >> a;
        h[a]++;
    }
    vector<int> ans;
    int cnt = n - 1;
    for (auto& [k, v] : h) {
        while (v > 0) {
            v -= cnt;
            ans.push_back(k);
            cnt--;
        }
    }
    for (auto& c : ans) cout << c << " ";
    cout << ans.back() << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}