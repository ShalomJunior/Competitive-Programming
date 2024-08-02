#include <bits/stdc++.h>
using namespace std;

const int N = 25;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    int O = 0;
    vector<vector<int>> p(N);
    for (int i = 0; i < n; i++) {
        O |= a[i];
        for (int j = 0; j < N; j++) {
            int mask = 1 << j;
            if (a[i] & mask) {
                p[j].push_back(i);
            }
        }
    }
    int ans = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < N; j++) {
            int mask = 1 << j;
            if (O & mask) {
                auto it = lower_bound(p[j].begin(), p[j].end(), i);
                if (it == p[j].end()) {
                    ans = max(ans, n - i + 1);
                }
                else {
                    ans = max(ans, *it - i + 1);
                }
            }
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}

