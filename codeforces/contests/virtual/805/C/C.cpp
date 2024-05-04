#include <bits/stdc++.h>
#define Mine pair<int,int>
#define F first
#define S second
using namespace std;

void solve() {
    int n, q; cin >> n >> q;
    map<int, Mine> h;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        if (!h.count(a))h[a].F = h[a].S = i;
        else h[a].S = i;
    }
    while (q--) {
        int a, b; cin >> a >> b;
        if (!h.count(a) || !h.count(b)) { cout << "NO" << endl; }
        else {
            cout << ((h[a].F < h[b].S) ? "YES" : "NO") << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}