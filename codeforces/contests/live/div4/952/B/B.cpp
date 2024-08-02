#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int cnt = 0;
    int ans = 2;
    for (int i = 2; i <= n; i++) {
        int curr = 0;
        for (int j = i; j <= n; j += i) curr++;
        if (curr >= cnt) {
            cnt = curr;
            ans = i;
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
