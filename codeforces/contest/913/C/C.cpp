#include <bits/stdc++.h>
using namespace std;

const int N = 26;
void solve() {
    int n; string s;
    cin >> n >> s;
    vector<int> a(N);
    int M = 0;
    for (auto& c : s) {
        M = max(M, ++a[c - 'a']);
    }
    int r = n - M;
    int ans = max(M - r, 0);
    if (n & 1) ans = max(ans, 1);
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
