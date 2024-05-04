#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> ans;
    for (int i = 0, j = 1; i < n; i++) {
        int a; cin >> a;
        if (a != j) { ans.push_back(j - 1); j = 1; }
        j++;
        if (i == n - 1)ans.push_back(j - 1);
    }
    cout << ans.size() << endl;
    for (auto& c : ans) cout << c << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}