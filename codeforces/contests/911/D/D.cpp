#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<vector<int>> ds(N);

vector<int> g(int n) {
    set<int> s;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            s.insert(i);
            s.insert(n / i);
        }
    }
    return vector<int>(s.begin(), s.end());
}

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    sort(a.begin(), a.end());
    int M = a[n - 1];
    vector<int> cnt(M + 1);
    for (int i = 0; i < n - 1; i++) {
        for (auto& d : ds[a[i]]) {
            cnt[d]++;
        }
    }
    vector<long long> sub(M + 1);
    long long x = 0;
    for (int i = M; i > 0; i--) {
        int m = cnt[i];
        long long tot = 1LL * m * (m - 1) / 2 - sub[i];
        x += tot * i;
        for (auto& c : ds[i]) {
            sub[c] += tot;
        }
    }
    cout << x << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 1; i < N; i++) ds[i] = g(i);
    int t; cin >> t;
    while (t--) solve();
}
