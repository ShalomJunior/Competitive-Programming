#include <bits/stdc++.h>
#define int long long 
using namespace std;

void solve() {
    int n; cin >> n;
    string s = to_string(n);
    map<char, int> cnt;
    for (auto& c : s)cnt[c]++;
    int m = s.size();
    for (int i = m - 1; i >= 0; i--) {
        if (s[i] == '0') {
            for (int j = i - 1; j >= 0; j--) {
                if (s[j] == '0' || s[j] == '5') {
                    cout << m - j - 2 << endl;
                    return;
                }
                else if (cnt[s[j]] > 1)break;
            }
        }
        if (s[i] == '5') {
            for (int j = i - 1; j >= 0; j--) {
                if (s[j] == '2' || s[j] == '7') {
                    cout << m - j - 2 << endl;
                    return;
                }
                else if (cnt[s[j]] > 1)break;
            }
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}