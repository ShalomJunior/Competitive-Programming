#include <bits/stdc++.h>
using namespace std;

const int N = 9;
void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(m);
    for (auto& c : a) cin >> c;
    set<int> mis;
    for (int i = 1; i <= n; i++) mis.insert(i);
    vector<int> q(k);
    for (auto& c : q) {
        cin >> c;
        mis.erase(c);
    }
    for (int i = 0; i < m; i++) {
        int id = a[i];
        if ((mis.count(id) && k >= n - 1) || k == n) {
            cout << 1;
        }
        else cout << 0;
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
