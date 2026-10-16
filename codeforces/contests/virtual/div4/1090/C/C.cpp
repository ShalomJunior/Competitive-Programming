#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    set<int> s;
    int N = 3 * n;
    for (int i = 1; i <= N; i++) s.insert(i);
    vector<int> ans(N);
    for (int i = 0; i < N; i += 3) {
        ans[i] = *prev(s.end());
        s.erase(ans[i]);
        ans[i + 1] = *prev(s.end());
        s.erase(ans[i + 1]);
        ans[i + 2] = *s.begin();
        s.erase(ans[i + 2]);
    }
    for (auto& c : ans) cout << c << " ";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}