#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e16;
int get(const vector<int>& a) {
    int n = a.size();
    vector<int> dp(n);
    dp[0] = INF;
    dp[1] = a[0] + a[1];
    for (int i = 2; i < n; ++i) {
        dp[i] = min(a[i - 1] + a[i], dp[i - 2] + a[i - 1] + a[i]);
    }
    return *min_element(dp.begin(), dp.end());
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    int s = accumulate(a.begin(), a.end(), 0LL);
    int val = get(a);
    if (val < 0) {
        cout << max(abs(s), s - val * 2);
    }
    else {
        cout << abs(s);
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}