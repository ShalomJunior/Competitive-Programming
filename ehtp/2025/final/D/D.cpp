#include<bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e18;
void solve() {
    string s;
    cin >> s;
    int n = s.length();
    int m = n + n % 2;
    string mn = string(m / 2, '4') + string(m / 2, '7');
    string mx = string(m / 2, '7') + string(m / 2, '4');
    if (n & 1 || s == "1000000000") {
        cout << mn << endl;
        return;
    }
    if (stoll(s) <= stoll(mx)) {
        int ans = INF;
        do {
            if (stoll(s) <= stoll(mn)) ans = min(ans, stoll(mn));
        } while (next_permutation(mn.begin(), mn.end()));
        cout << ans << endl;
    }
    else {
        cout << 4 << mn << 7 << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}