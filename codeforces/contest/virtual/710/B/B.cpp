#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
void solve() {
    int n, k; string s; cin >> n >> k >> s;
    int L = INF, R = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '*') {
            L = min(L, i);
            R = max(R, i);
        }
    }
    int ans = 0;
    L == R ? ans++ : ans += 2;
    for (int i = L; i < R - k;) {
        for (int j = i + k; j > i; j--) {
            if (s[j] == '*') {
                i = j;
                ans++;
                break;
            }
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