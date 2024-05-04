#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    int ans = INF;
    for (int i = 1; i <= 100; i++) {
        set<int> s;
        for (auto& c : a) {
            if (i != c)s.insert(abs(i - c));
        }
        int m = s.size();
        if (m < 2) {
            ans = min(ans, m ? *s.begin() : 0);
        }
    }
    cout << (ans == INF ? -1 : ans) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}