#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, x; cin >> n >> x;
    if (n % x) {
        cout << -1 << endl;
        return;
    }
    vector<int> ans(n + 1);
    iota(ans.begin(), ans.end(), 0);
    ans[1] = x; ans[x] = n; ans[n] = 1;
    for (int i = 2; i <= n; i++) {
        if (ans[i] == n) {
            bool done = false;
            for (int j = 2 * i; j < n; j += i) {
                if (ans[j] % i == 0 && n % j == 0) {
                    swap(ans[i], ans[j]);
                    done = true;
                    break;
                }
            }
            if (!done)break;
        }
    }

    for (int i = 1; i <= n;i++)cout << ans[i] << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}