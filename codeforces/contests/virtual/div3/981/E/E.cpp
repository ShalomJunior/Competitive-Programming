#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
        h[p[i]] = i;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (p[p[i]] != i) {
            int f = p[i];
            int s = h[i];
            swap(p[f], p[s]);
            h[p[f]] = f;
            h[p[s]] = s;
            ans++;
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}