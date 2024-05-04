#include <bits/stdc++.h>
#define Mine pair<int,int>
#define F first
#define S second
using namespace std;

const long long INF = 5e18;
void solve() {
    int n, p; cin >> n >> p;
    vector<Mine> a(n);
    for (int i = 0; i < 2 * n; i++) {
        if (i < n) cin >> a[i].F;
        else cin >> a[i - n].S;
    }
    sort(a.begin(), a.end(), [](Mine& a, Mine& b) {
        if (a.S != b.S) return a.S < b.S;
        return a.F > b.F;
        }
    );
    int can = 0; long long cost = 0;
    for (int i = 0; i < n; i++) {
        int r = n - can - 1;
        int share = min(r, a[i].F);
        cost += 1LL * share * a[i].S + p;
        can += 1 + share;
        if (share == r) break;
    }
    cout << min(1LL * n * p, cost ? cost : INF) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}