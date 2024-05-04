#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            set<int> s;
            for (int k = 1; k <= n; k++) {
                if (k != j) s.insert(k);
            }
            int M = i * j;
            int id = n, curr = 0;
            bool b = true;
            while (!s.empty()) {
                if (id == i) {
                    id--;
                    continue;
                }
                auto it = s.upper_bound(M / id);
                if (it == s.begin()) {
                    b = false;
                    break;
                }
                --it;
                curr += *it * id;
                s.erase(it);
                id--;
            }
            if (b) ans = max(ans, curr);
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