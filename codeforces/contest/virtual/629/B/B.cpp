#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    if (k == 1) {
        cout << (string(n - 2, 'a') + "bb") << endl;
        return;
    }
    long long c = 1, id = 1;
    for (int i = n - 3; i >= 0; i--, c++) {
        if (id + 1 + c < k) {
            id += 1 + c;
            continue;
        }
        string ans(n, 'a');
        ans[i] = 'b';
        int rem = k - (id + 1);
        ans[(n - 1) - rem] = 'b';
        cout << ans << endl;
        return;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}