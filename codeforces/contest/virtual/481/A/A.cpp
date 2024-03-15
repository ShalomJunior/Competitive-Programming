#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    set<int> s;
    vector<int> ans;
    for (int i = n - 1; i >= 0; i--) {
        if (!s.count(a[i])) {
            ans.push_back(a[i]);
            s.insert(a[i]);
        }
    }
    int  m = ans.size();
    cout << m << endl;
    for (int i = m - 1; i >= 0; i--) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}