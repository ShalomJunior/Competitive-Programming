#include <bits/stdc++.h>
#define int long long
using namespace std;

int f(int l, int r) {
    int n = r - l + 1;
    return n * (l + r) / 2;
}

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    if (b <= a) {
        cout << n * a;
    }
    else if (b - (n - 1) >= a) {
        cout << f(b - n + 1, b);
    }
    else {
        int k = b - a + 1;
        cout << f(b - k + 1, b) + (n - k) * a;
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
