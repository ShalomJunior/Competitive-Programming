#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    map<int, pair<int, int>> x;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        i & 1 ? x[a[i]].second++ : x[a[i]].first++;
    }
    sort(a.begin(), a.end());
    map<int, pair<int, int>> y;
    for (int i = 0; i < n; i++) {
        i & 1 ? y[a[i]].second++ : y[a[i]].first++;
    }
    for (auto& [k, v] : x) {
        if (y[k] != v) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}