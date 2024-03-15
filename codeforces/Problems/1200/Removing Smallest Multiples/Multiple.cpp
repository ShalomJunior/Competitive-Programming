#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; string s; cin >> n >> s;
    long long ans = 0;
    vector<bool> done(n);
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            if (s[j - 1] != '0')break;
            else {
                if (!done[j - 1]) {
                    done[j - 1] = true;
                    ans += (long long)i;
                }
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