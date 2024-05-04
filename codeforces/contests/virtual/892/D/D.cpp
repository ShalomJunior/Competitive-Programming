#include <bits/stdc++.h>
using namespace std;

string ALPHA = "abcdefghijklmnopqrstuvwxyz";
void solve() {
    int n; cin >> n;
    if (n < 3) {
        cout << (n == 1 ? "a" : "ab") << endl;
        return;
    }
    int i = 1;
    while (n % i == 0) i++;
    string ans, t = ALPHA.substr(0, i);
    ans.reserve(n);
    while (ans.length() + i <= n) ans += t;
    int rem = n - ans.size();
    if (rem) ans += t.substr(0, rem);
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}