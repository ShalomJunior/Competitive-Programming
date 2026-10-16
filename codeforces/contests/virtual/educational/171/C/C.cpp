#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e18;
void solve() {
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    int i = n - 1;
    int j = n - 1;
    while (i >= 0 && j >= 0) {
        while (j >= i) {
            if (s[j] == '0') ans += j + 1;
            j--;
        }
        if (s[i] == '1') {
            while (j >= 0 && s[j] == '1') j--;
            bool f = false;
            while (j >= 0 && s[j] == '0') {
                f = true;
                ans += j + 1;
                j--;
            }
            if (f) i--;
        }
        else i--;
    }
    deque<int> r;
    for (int k = 0; k <= i; k++) {
        if (s[k] == '1') {
            r.push_back(k + 1);
        }
    }
    while (!r.empty()) {
        ans += r.front();
        r.pop_back();
        if (!r.empty()) r.pop_front();
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
