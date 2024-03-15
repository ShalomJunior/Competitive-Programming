#include <bits/stdc++.h>
using namespace std;

void solve() {
    int x, y;
    cin >> x >> y;
    vector<int>ans;
    for (int i = y; i < x; i++) ans.push_back(i);
    for (int i = x; i > y; i--) ans.push_back(i);
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