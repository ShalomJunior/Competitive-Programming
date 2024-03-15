#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second
using namespace std;

ll arr(ll n, ll k) {
    ll ans = 1;
    for (ll i = n - k + 1; i <= n; ++i) ans *= i;
    return ans;
}

void solve() {
    int n; cin >> n;
    vector<int> v;
    unordered_map<int, ll> is;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        if (is.find(a) == is.end()) {
            v.push_back(a);
        }
        is[a]++;
    }

    sort(v.begin(), v.end());

    ll ans = 0;
    int len = (int)v.size();
    for (int i = 0; i < len; i++) {
        int curr = v[i];
        int m = v[len - 1] / curr;
        for (int j = 1; j * j <= m;j++) {
            if (j == 1) {
                if (is[curr] >= 3)ans += arr(is[curr], 3);
            }
            else if (is.find(curr * j) != is.end() && is.find(curr * j * j) != is.end()) {
                ans += is[curr] * is[curr * j] * is[curr * j * j];
            }
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