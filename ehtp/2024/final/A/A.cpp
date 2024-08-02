#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        a += n - 1;
        b += n - 1;
        int cnt = 0;
        while (a != b) {
            a /= 2;
            b /= 2;
            cnt++;
        }
        cout << cnt << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}