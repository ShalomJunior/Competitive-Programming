#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    map<int, int> idx;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
        idx[sum] = i;
    }
    int ans = 1e9;
    auto f = [&](int q) {
        bool good = true;
        int curr = 0;
        for (int j = q; j <= sum; j += q) {
            if (!idx.count(j)) {
                good = false;
                break;
            }
            else {
                if (j == q) curr += idx[j];
                else curr += idx[j] - idx[j - q] - 1;
            }
        }
        if (good) ans = min(ans, curr);
        };
    for (int i = 1; i * i <= sum; i++) {
        if (sum % i) continue;
        f(i); f(sum / i);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}