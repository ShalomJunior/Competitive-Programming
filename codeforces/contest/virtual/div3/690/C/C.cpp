#include <bits/stdc++.h>
using namespace std;

void solve() {
    int x; cin >> x;
    if (x > 45) { cout << -1 << endl; return; }
    vector<int> dig;
    for (int i = 9; i > 0; i--) {
        if (x >= i) {
            dig.push_back(i);
            x -= i;
        }
    }
    sort(dig.rbegin(), dig.rend());
    int ans = 0;
    for (int i = 0; i < dig.size(); i++) {
        ans += dig[i] * pow(10, i);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}