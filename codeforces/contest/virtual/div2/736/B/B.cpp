#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; string a, b;
    cin >> n >> a >> b;
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        if (b[i] == '0') continue;
        if (i && a[i - 1] == '1' && !ans[i - 1]) {
            ans[i - 1] = 1;
            continue;
        }
        if (a[i] == '0') {
            ans[i] = 1;
            continue;
        }
        if (i + 1 < n && a[i + 1] == '1') {
            ans[i + 1] = 1;
            continue;
        }
    }
    cout << count(ans.begin(), ans.end(), 1) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}