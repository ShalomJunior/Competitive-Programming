#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a[i] -= x;
    }
    int M = *max_element(a.begin(), a.end());
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (a[i] == M) ans.push_back(i + 1);
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