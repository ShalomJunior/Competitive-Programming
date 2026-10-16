#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, d;
    cin >> n >> d;
    vector<int> ans = { 1 };
    if (d % 3 == 0 || n >= 3) ans.push_back(3);
    if (d == 5) ans.push_back(5);
    if (d == 7 || n >= 3) ans.push_back(7);
    else {
        if (n == 2 && (d * 10 + d) % 7 == 0) ans.push_back(7);
    }
    if (d == 9) ans.push_back(9);
    else {
        int m = d % 3 ? 1 : 3;
        if (n >= 3) m *= 3;
        if (n >= 6) m *= 3;
        if (m % 9 == 0) ans.push_back(9);
    }
    for (auto& c : ans) cout << c << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
