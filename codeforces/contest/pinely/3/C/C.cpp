#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<pair<int, int>> a(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        cin >> a[i].first;
        if (i >= n) a[i].second = 1;
    }
    vector<int> c(n);
    for (auto& x : c) cin >> x;
    sort(a.begin(), a.end());
    sort(c.rbegin(), c.rend());
    stack<int> st;
    vector<int> b;
    for (int i = 0; i < 2 * n; i++) {
        if (a[i].second == 0) st.push(a[i].first);
        else {
            int j = st.top(); st.pop();
            b.push_back(a[i].first - j);
        }
    }
    sort(b.begin(), b.end());
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += (long long)b[i] * c[i];
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
