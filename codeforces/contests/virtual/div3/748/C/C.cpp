#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int diff(string a, string b) {
    int n = a.length();
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i])continue;
        ans += abs(a[i] - b[i]);
    }
    return ans;
}

void solve() {
    int n, s; cin >> n >> s;
    vector<string> v(n);
    for (auto& str : v) cin >> str;
    int ans = INF;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            ans = min(ans, diff(v[i], v[j]));
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