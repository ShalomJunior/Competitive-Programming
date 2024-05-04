#include <bits/stdc++.h>
using namespace std;

const int N = 20;
void solve() {
    int n, m; cin >> n >> m;
    vector<long long> a(n), b(m);
    for (auto& c : a) cin >> c;
    for (auto& c : b) cin >> c;
    sort(a.begin(), a.end());
    long long ans = 0;
    set<long long> vals;
    for (int i = N; i >= 0; i--) {
        int mask = 1 << i;
        if ((n & mask) == 0) continue;
        vector<long long> vec;
        for (int j = 0; j < mask; j++) {
            vec.push_back(a.back());
            a.pop_back();
        }
        vector<long long> tmp;
        while (vec.size() >= 2) {
            for (int i = 0; i < vec.size(); i += 2) {
                ans = gcd(ans, 1LL * (a[i] - a[i + 1]));
                tmp.push_back(a[i + 1]);
            }
            vec = tmp;
            tmp = {};
        }
        vals.insert(vec[0]);
    }
    for (int i = 0; i < m; i++) {
        long long x = ans;
        for (auto it = vals.begin(); it != vals.end(); it++) {
            x = gcd(x, *it + b[i]);
        }
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
