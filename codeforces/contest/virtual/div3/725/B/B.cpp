#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    int sum = accumulate(a.begin(), a.end(), 0);
    if (sum % n) {
        cout << -1 << endl;
        return;
    }
    int cnt = 0;
    for (auto& c : a) {
        if (c > sum / n) cnt++;
    }
    cout << cnt << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}