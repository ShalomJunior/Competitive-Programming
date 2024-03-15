#include <bits/stdc++.h>
using namespace std;

const int INF = 2e9;
void solve() {
    int n, m, d; cin >> n >> m >> d;
    vector<int> s(m);
    for (auto& c : s) cin >> c;
    int base = m;
    vector<int> v(m + 1);
    for (int i = 0; i <= m; i++) {
        if (i == 0) {
            int cnt = s[i] - 1;
            if (s[i] != 1) {
                v[i] = max(cnt / d, 1);
            }
        }
        else if (i == m) {
            int cnt = n - s[i - 1] - 1;
            if (s[i] != n) {
                v[i] = cnt / d;
            }
        }
        else {
            int cnt = s[i] - s[i - 1] - 1;
            v[i] = cnt / d;
        }
        base += v[i];
    }
    cout << "base = " << base << endl;
    int ans = INF, id;
    for (int i = 0; i < m; i++) {
        int curr = base - v[i] - v[i + 1] - 1;
        cout << "curr = " << curr << endl;
        int cnt = (i + 1 < m ? s[i + 1] : n) - (i - 1 >= 0 ? s[i - 1] : 1) - 1;
        cout << "cnt = " << cnt << endl;
        curr += cnt / d;
        if (cnt < ans) {
            ans = cnt;
            id = i + 1;
        }
    }
    cout << ans << " " << id << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}