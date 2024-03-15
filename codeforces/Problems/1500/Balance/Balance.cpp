#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int q; cin >> q;
    set<int> s;
    while (q--) {
        char c; int i; cin >> c >> i;
        if (c == '+')s.insert(i);
        else {
            int cnt = i;
            bool done = false;
            while (cnt <= *prev(s.end()) && *s.lower_bound(cnt) == cnt) cnt += i;
            cout << cnt << endl;
        }
    }

}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}