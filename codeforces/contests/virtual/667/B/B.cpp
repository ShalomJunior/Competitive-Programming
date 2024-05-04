#include <bits/stdc++.h>
#define int long long
#define F first
#define S second 
using namespace std;

void solve() {
    int n; pair<int, int> a, b;
    cin >> a.F >> b.F >> a.S >> b.S >> n;
    if (a.F > b.F || (a.F == b.F && a.S > b.S)) swap(a, b);
    int m = min(n, a.F - a.S);
    a.F -= m; n -= m;
    m = min(n, b.F - b.S);
    b.F -= m; n -= m;
    cout << a.F << " " << b.F << endl;
    cout << a.F * b.F << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}