#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
void solve() {
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    sort(a.begin(), a.end());
    int ans = 0;
    do {
        int cnt = 0;
        int mn = INF;
        for (int i = 0; i < n; i++) {
            cnt += a[i];
            mn = min(mn, a[i]);
            if (cnt >= s) {
                if (cnt - s < mn) {
                    ans = max(ans, i + 1);
                }
                break;
            }
        }
    } while (next_permutation(a.begin(), a.end()));
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}