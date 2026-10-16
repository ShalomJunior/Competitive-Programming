#include <bits/stdc++.h>
#define int long long
using namespace std;

int query(int type, int l, int r) {
    cout << type << " " << l + 1 << " " << r + 1 << endl;
    cout.flush();
    int res;
    cin >> res;
    return res;
}

void solve() {
    int n;
    cin >> n;
    int l = 0, r = n - 1;
    while (l < r) {
        int mid = (l + r) / 2;
        int f = query(1, 0, mid);
        int g = query(2, 0, mid);
        if (f == g) {
            l = mid + 1;
        }
        else {
            r = mid;
        }
    }
    int len = query(2, 0, n - 1) - query(1, 0, n - 1);
    cout << "! " << r + 1 << " " << r + len << endl;
    cout.flush();
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
