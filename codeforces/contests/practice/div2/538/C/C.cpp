#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e18;
int f(int a, int n) {
    int j = 0;
    while (pow(a, j + 1) <= n) j++;
    return j;
}

void solve() {
    int n, b;
    cin >> n >> b;
    if (n == 1) {
        cout << 0 << endl;
        return;
    }
    vector<pair<int, int>> p;
    int x = b;
    for (int i = 2; i * i <= b; i++) {
        int cnt = 0;
        while (x % i == 0) {
            cnt++;
            x /= i;
        }
        if (cnt) p.push_back({ i, cnt });
    }
    if (x > 1) p.push_back({ x, 1 });
    int mn = INF;
    for (auto& [k, cnt] : p) {
        int mx = f(k, n);
        vector<int> a(mx + 2);
        for (int i = 1, m = k; i <= mx; i++, m *= k) a[i] = n / m;
        int tot = 0;
        for (int i = mx; i > 0; i--) {
            int v = a[i] - a[i + 1];
            tot += v * i;
        }
        mn = min(mn, tot / cnt);
        cerr << tot / cnt << endl;
    }
    cout << mn << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
