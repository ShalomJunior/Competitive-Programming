#include <bits/stdc++.h>
#define ll long long 
using namespace std;

bool ang(ll n, ll m, ll x, ll y) {
    bool ans = (x == 1 && y == 1);
    ans |= (x == 1 && y == m);
    ans |= (x == n && y == 1);
    ans |= (x == n && y == m);
    return ans;
}

bool board(ll n, ll m, ll x, ll y) {
    bool ans = (x == 1 || x == n);
    ans |= (y == 1 || y == m);
    return ans;
}

void solve() {
    ll n, m; cin >> n >> m;
    ll x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;

    if (ang(n, m, x1, y1) || ang(n, m, x2, y2)) {
        cout << 2 << endl;
        return;
    }

    if (board(n, m, x1, y1) || board(n, m, x2, y2)) {
        cout << 3 << endl;
        return;
    }
    cout << 4 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}