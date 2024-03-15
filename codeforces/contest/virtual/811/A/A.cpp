#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, h, m; cin >> n >> h >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        int f, s; cin >> f >> s;
        a[i] = 60 * f + s;
    }
    sort(a.begin(), a.end());
    int t = 60 * h + m;
    auto it = lower_bound(a.begin(), a.end(), t);
    if (it != a.end()) {
        int rest = *it - t;
        cout << rest / 60 << " " << rest % 60 << endl;
    }
    else {
        int rest = a[0] + (1440 - t);
        cout << rest / 60 << " " << rest % 60 << endl;
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}