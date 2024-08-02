#include <bits/stdc++.h>
using namespace std;

int f(vector<int>& g) {
    return accumulate(g.begin(), g.end(), 0);
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    auto work = [&](vector<int> g, stringstream& ss, int id) {
        int m = g.size();
        if (m == 0) return 0;
        cerr << "m = " << m << endl;
        if (f(g) > m * m) {
            ss << id + 1 << " " << id + m << endl;
        }
        else {
            for (int i = 0; i < m; i++) {

            }
        }
        return max(f(g), m * m);
        };
    int ans = work(a);
    stringstream out;
    for (int i = 1; i < (1 << n); i++) {
        int s = 0;
        vector<int> temp;
        stringstream ss;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                s += a[j];
                s += work(temp);
                temp.clear();
            }
            else {
                temp.push_back(a[j]);
            }
        }
        s += work(temp);
        if (s >= ans) {
            out = ss;
        }
        ans = max(ans, s);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
