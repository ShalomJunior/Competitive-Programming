#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
void solve() {
    int n; string s;
    cin >> n >> s;
    int ans = INF;
    for (char c = 'a'; c <= 'z'; c++) {
        int l = 0, r = n - 1;
        int curr = 0;
        while (l < r) {
            if (s[l] == s[r]) {
                l++, r--;
            }
            else {
                if (s[l] != c && s[r] != c) {
                    curr = INF;
                    break;
                }
                else {
                    curr++;
                    s[l] == c ? l++ : r--;
                }
            }
        }
        ans = min(ans, curr);
    }
    cout << (ans == INF ? -1 : ans) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}