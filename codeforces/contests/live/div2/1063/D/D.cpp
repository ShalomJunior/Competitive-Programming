#include <bits/stdc++.h>
using namespace std;

int query(int i, int x) {
    cout << "? " << i + 1 << " " << x << endl;
    cout.flush();
    int res;
    cin >> res;
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<int> s(n);
    vector<int> idx(n - 1);
    iota(s.begin(), s.end(), 1);
    iota(idx.begin(), idx.end(), 0);
    int m = 1;
    while (s.size() > 1) {
        int z = s.size();
        vector<int> r(z);
        for (int i = 0; i < z; i++) {
            if (s[i] & m) {
                r[i] = 1;
            }
        }
        int k = idx.size();
        vector<int> q(k);
        for (int i = 0; i < k; i++) {
            q[i] = query(idx[i], m);
        }
        int f = accumulate(r.begin(), r.end(), 0);
        int g = accumulate(q.begin(), q.end(), 0);
        vector<int> ns;
        vector<int> nidx;
        if (f == g) {
            for (int i = 0; i < z; i++) {
                if (!r[i]) {
                    ns.push_back(s[i]);
                }
            }
            for (int i = 0; i < k; i++) {
                if (!q[i]) {
                    nidx.push_back(idx[i]);
                }
            }
        }
        else {
            for (int i = 0; i < z; i++) {
                if (r[i]) {
                    ns.push_back(s[i]);
                }
            }
            for (int i = 0; i < k; i++) {
                if (q[i]) {
                    nidx.push_back(idx[i]);
                }
            }
        }
        m *= 2;
        s = ns;
        idx = nidx;
    }
    cout << "! " << s[0] << endl;
    cout.flush();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
