#include <bits/stdc++.h>
#define Mine pair<int, int>
#define F first
#define S second
using namespace std;

struct query {
    int i, s, d, k;
    bool operator<(const query& o) const {
        if (d != o.d) return d < o.d;
        return s % d < o.s % o.d;
    }
    bool operator&(const query& o) const {
        return s % d == o.s % o.d && d == o.d;
    }
};

void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    vector<query> qs(q);
    for (int i = 0; i < q; i++) {
        qs[i].i = i;
        cin >> qs[i].s >> qs[i].d >> qs[i].k;
        --qs[i].s;
    }
    sort(qs.begin(), qs.end());
    int m;
    vector<long long> x(n), y(n);
    vector<long long> ans(q);
    for (int i = 0; i < q; i++) {
        int s = qs[i].s, d = qs[i].d, k = qs[i].k;
        Mine p = { s % d, d };
        if (i == 0 || !(qs[i] & qs[i - 1])) {
            vector<int> temp;
            for (int j = p.F; j < n; j += p.S) temp.push_back(a[j]);
            m = temp.size();
            for (int j = m - 1; j >= 0; --j) {
                x[j] = temp[j];
                y[j] = temp[j];
                if (j < m - 1) {
                    x[j] += (x[j + 1] + y[j + 1]);
                    y[j] += y[j + 1];
                }
            }
        }
        int j = (s - p.F) / p.S;
        long long res = x[j];
        if (j + k < m) {
            res -= x[j + k];
            res -= y[j + k] * k;
        }
        ans[qs[i].i] = res;
    }
    for (auto& c : ans) cout << c << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
