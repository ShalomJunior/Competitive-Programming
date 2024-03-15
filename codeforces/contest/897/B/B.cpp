#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<set<int>> a(n);
    set<int> s;
    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        for (int j = 0; j < k; j++) {
            int x; cin >> x;
            a[i].insert(x);
            s.insert(x);
        }
    }
    int ans = 0;
    for (auto it = s.begin(); it != s.end(); it++) {
        set<int> temp;
        for (auto& all : a) {
            if (!all.count(*it)) {
                temp.insert(all.begin(), all.end());
            }
        }
        ans = max(ans, (int)temp.size());
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}