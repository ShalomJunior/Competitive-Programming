#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    set<int> ans;
    ans.insert(0);
    for (int i = 1; i * i <= n; i++)
        ans.insert(i), ans.insert(n / i);

    cout << ans.size() << endl;
    for (auto& v : ans)
        cout << v << " ";
    cout << endl;
}
int main() {
    int t; cin >> t;
    while (t--) solve();
}