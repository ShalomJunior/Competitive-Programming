#include <bits/stdc++.h>
#define int long long
using namespace std;

int f(int n) {
    int m = 1;
    while (m <= n) m <<= 1;
    return m;
}
void solve() {
    int l, r;
    cin >> l >> r;
    set<int> s;
    for (int i = l; i <= r; i++) s.insert(i);
    map<int, int> h;
    for (int i = r; i >= l; i--) {
        if (!h.count(i)) {
            int j = f(i) - 1 - i;
            if (j >= l) {
                h[i] = j;
                h[j] = i;
                s.erase(i);
                s.erase(j);
            }
        }
    }
    for (auto& [k, v] : h) cout << k << "-> ";
    cout << endl;
    int sum = 0;
    for (int i = l; i <= r; i++) {
        if (!h.count(i)) {
            int x = *s.begin();
            h[i] = x;
            s.erase(x);
        }
        sum += (i | h[i]);
    }
    cout << sum << endl;
    for (int i = l; i <= r; i++) cout << h[i] << " ";
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
