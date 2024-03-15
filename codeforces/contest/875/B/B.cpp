#include <bits/stdc++.h>
using namespace std;

void read(int n, map<int, int>& h) {
    int cnt = 1; int last;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        if (!i) last = a;
        else {
            if (a == last)cnt++;
            else {
                h[last] = max(h[last], cnt);
                cnt = 1; last = a;
            }
        }
    }
    h[last] = max(h[last], cnt);
}

void solve() {
    int n; cin >> n;
    map<int, int> a, b;
    read(n, a); read(n, b);
    int ans = 0;
    for (auto& [k, v] : a) {
        ans = max(ans, v + b[k]);
    }
    for (auto& [k, v] : b) {
        ans = max(ans, v + a[k]);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}