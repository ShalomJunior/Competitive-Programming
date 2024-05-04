#include <bits/stdc++.h>

using namespace std;

int sm(int n) {
    int ans = 0;
    while (n > 0) {
        ans += n % 10;
        n /= 10;
    }
    return ans;
}

void solve() {
    int n, q; cin >> n >> q;
    vector<int> v(n);
    set<int> s;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (v[i] > 9)s.insert(i);
    }

    for (int i = 0; i < q; i++) {
        int t; cin >> t;
        if (t & 1) {
            int l, r; cin >> l >> r; --l; --r;
            while (!s.empty()) {
                auto it = s.lower_bound(l);
                if (it == s.end() || *it > r) break;
                v[*it] = sm(v[*it]);
                int idx = *it;
                s.erase(it);
                if (v[idx] > 9)s.insert(idx);
                l = idx + 1;
            }
        }
        else {
            int x; cin >> x; --x;
            cout << v[x] << endl;
        }
    }
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}