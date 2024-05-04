#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(2 * n);
    for (auto& c : a) cin >> c;
    vector<int> ans;
    queue<int> q;
    for (int i = 0; i < 2 * n; i++) {
        if (q.empty() || (!q.empty() && q.front() != a[i])) {
            q.push(a[i]);
            ans.push_back(a[i]);
        }
        else q.pop();
    }
    for (auto& c : ans) cout << c << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}