#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> v(n);
    for (auto& c : v)cin >> c;

    int ans = 0, curr = 0;
    for (int i = 0; i < n; i++) {
        if (!v[i])curr++;
        else {
            ans = max(ans, curr);
            curr = 0;
        }
    }
    cout << max(ans, curr) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}