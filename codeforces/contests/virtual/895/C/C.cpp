#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> ans;
    ans.push_back(n);
    while (n > 1) {
        if (n & 1) ans.push_back(--n);
        n /= 2;
        ans.push_back(n);
    }
    cout << ans.size() << endl;
    for (auto& c : ans) cout << c << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}