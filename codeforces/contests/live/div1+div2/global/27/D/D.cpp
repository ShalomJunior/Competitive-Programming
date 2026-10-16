#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e9;
const int MOD = 1e9 + 7;

int pow(int a, int b, int mod) {
    int res = 1;
    while (b) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    int k = 0;
    int s = 0;
    int m = 0;
    vector<int> mx(n + 1);
    vector<int> cnt(n + 1);
    vector<int> ans(n + 1);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        while (x % 2 == 0) {
            cnt[i]++;
            x /= 2;
        }
        mx[i] = x;
        if (mx[i] > mx[i - 1]) {

        }
        else {
            ans[i] = (ans[i - 1])
                cout << ans[]
        }
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}