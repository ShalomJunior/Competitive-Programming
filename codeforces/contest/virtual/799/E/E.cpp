#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, s; cin >> n >> s;
    vector<int> a(n);
    int pop = 0;
    map<int, int> ft, bc;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i]) {
            pop++;
            ft[pop] = i + 1;
        }
    }
    pop = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i]) {
            pop++;
            bc[pop] = n - i;
        }
    }
    if (pop < s) { cout << -1 << endl; return; }
    int ans = 1e9;
    for (int i = 0; i <= pop - s; i++) {
        ans = min(ans, ft[i] + bc[pop - s - i]);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}