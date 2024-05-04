#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    int o = 0, e = 0;
    long long tot = 0;
    for (int i = 0; i < n; i++) {
        tot += a[i];
        a[i] & 1 ? o++ : e++;
        int lost = o / 3;
        if (o % 3 == 1) lost++;
        cout << tot - (i ? lost : 0) << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
