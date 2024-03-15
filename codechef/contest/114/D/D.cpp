#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    int w = n / 2 + 1;
    int l = n - w;
    string ans;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'R') {
            ans += 'P';
            continue;
        }
        if (s[i] == 'P') {
            if (l) {
                ans += 'P';
                l--;
            }
            else ans += 'S';
            continue;
        }
        if (s[i] == 'S') {
            if (l) {
                ans += 'P';
                l--;
            }
            else ans += 'R';
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
