#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto& c : a)cin >> c;
    int s = accumulate(a.begin(), a.end(), 0LL);
    set<int> v;
    for (int i = 0; i < n; i++)v.insert(i);
    int last = -1;
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int j, x;
            cin >> j >> x;
            j--;
            if (v.count(j)) {
                s += (x - a[j]);
            }
            else {
                s += (x - last);
                a[j] = x;
                v.insert(j);
            }
            a[j] = x;
        }
        else {
            int x;
            cin >> x;
            s = n * x;
            last = x;
            v.clear();
        }
        cout << s << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}