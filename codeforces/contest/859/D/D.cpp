#include <bits/stdc++.h>
#define ll long long

using namespace std;

int get(int l, int r, vector<ll>& v) {
    if (l > r) return 0;
    int ans = 0;
    while (l != r) {
        if (l & 1) ans += v[l++];

        if (r % 2 == 0) ans += v[r--];

        l /= 2; r /= 2;
    }
    return ans + v[l];
}

int sze(int n) {
    int exp = log2(n);
    return ((pow(2, exp) == n) ? n : pow(2, exp + 1));
}

void solve() {
    int n, q; cin >> n >> q;
    int sz = 2 * sze(n);
    vector<ll> v(sz);
    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        v[sz / 2 + i] = k % 2;
    }

    for (int i = sz / 2 - 1; i > 0; i--) {
        v[i] = v[2 * i] + v[2 * i + 1];
        v[i] %= 2;
    }

    for (int i = 0; i < q; i++) {
        ll l, r, k; cin >> l >> r >> k;
        l--; r--;
        ll temp = 0;
        temp += get(sz / 2, sz / 2 + l - 1, v);
        temp += get(sz / 2 + r + 1, sz - 1, v);
        temp += (r - l + 1) * k;
        temp %= 2;
        cout << ((temp) ? "YES" : "NO") << endl;
    }

}

int main() {
    int t; cin >> t;
    while (t--)solve();
}