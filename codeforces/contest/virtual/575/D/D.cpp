#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
string base;
void prepare() {
    for (int i = 0; i < 1000; i++)
        base += "RGB";
}

int diff(string a, string b) {
    int ans = 0;
    for (int i = 0; i < a.length(); i++) {
        if (a[i] != b[i]) ans++;
    }
    return ans;
}

void solve() {
    int n, k; string s;
    cin >> n >> k >> s;
    int ans = INF;
    for (int i = 0; i <= n - k; i++) {
        for (int j = 0; j < 3; j++) {
            ans = min(ans, diff(s.substr(i, k), base.substr(j, k)));
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    prepare();
    int t; cin >> t;
    while (t--) solve();
}