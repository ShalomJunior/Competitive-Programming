#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    map<int, int> h;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        h[x]++;
    }
    vector<int> a;
    for (auto& [k, v] : h) a.push_back(k);
    int m = a.size();
    vector<bool> ans(m, true);
    for (int i = 1; i < m; i++) {
        if (a[i - 1] < a[i] && a[i - 1] + k >= a[i]) {
            ans[i - 1] = false;
        }
    }
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        if (ans[i]) {
            cnt += h[a[i]];
        }
    }
    cout << cnt << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
