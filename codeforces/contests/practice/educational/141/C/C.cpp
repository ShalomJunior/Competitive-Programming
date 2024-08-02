#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(), [&](int i, int j) {
        return a[i] < a[j];
        });
    int wins = 0;
    int sum = 0;
    set<int> less;
    for (int i = 0; i < n && sum + a[p[i]] <= m; i++) {
        sum += a[p[i]];
        wins++;
        less.insert(p[i]);
    }
    if (wins == 0) {
        cout << n + 1 << endl;
        return;
    }
    if (wins == n) {
        cout << 1 << endl;
        return;
    }
    int rank = n - wins;
    bool f = less.count(wins);
    bool g = less.count(wins + 1);
    if (less.count(wins + 1)) rank--;
    if (!less.count())
        cerr << rank << "->" << endl;
    if (sum - a[p[wins - 1]] + a[wins + 1] <= m) rank--;
    cout << max(rank, 1) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}