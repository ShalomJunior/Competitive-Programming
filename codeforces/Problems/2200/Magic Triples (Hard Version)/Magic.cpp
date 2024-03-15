#include <bits/stdc++.h>
#define int long long
using namespace std;

int arr(int n, int k) {
    int ans = 1;
    for (int i = n - k + 1; i <= n; ++i) ans *= i;
    return ans;
}

void solve() {
    int n; cin >> n;
    vector<int> v;
    unordered_map<int, int> is;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        if (!is.count(a)) v.push_back(a);
        is[a]++;
    }

    sort(v.begin(), v.end());

    int ans = 0;
    int len = (int)v.size();
    for (int i = 0; i < len; i++) {
        int curr = v[i];
        int m = v[len - 1] / curr;
        for (int j = 1; j * j <= m;j++) {
            if (j == 1) {
                if (is[curr] >= 3)ans += arr(is[curr], 3);
            }
            else if (is.count(curr * j) && is.count(curr * j * j)) {
                ans += is[curr] * is[curr * j] * is[curr * j * j];
            }
        }
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}