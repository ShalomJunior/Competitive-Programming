#include <bits/stdc++.h>
using namespace std;

const int N = 26;
void solve() {
    string s;
    cin >> s;
    int n = s.length();
    vector<set<int>> a(N);
    for (int i = 0; i < n; i++) {
        a[s[i] - 'a'].insert(i);
    }
    int q;
    cin >> q;
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int p;
            char c;
            cin >> p >> c;
            p--;
            a[s[p] - 'a'].erase(p);
            s[p] = c;
            a[s[p] - 'a'].insert(p);
        }
        else {
            int l, r;
            cin >> l >> r;
            --l; --r;
            int cnt = 0;
            for (int i = 0; i < N; i++) {
                auto it = a[i].lower_bound(l);
                if (it != a[i].end() && *it <= r) cnt++;
            }
            cout << cnt << endl;
        }
    }
}

int  main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}