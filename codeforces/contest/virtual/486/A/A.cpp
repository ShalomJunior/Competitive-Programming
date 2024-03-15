#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    set<int> s;
    vector<int> ans;
    for (int i = 0; i < n;i++) {
        int x; cin >> x;
        if (!s.count(x)) {
            ans.push_back(i + 1);
            s.insert(x);
        }
    }
    int m = ans.size();
    if (m < k) { cout << "NO" << endl; return; }
    cout << "YES" << endl;
    for (int i = 0; i < k; i++)cout << ans[i] << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}