#include <bits/stdc++.h>
#define int long long
#define Mine pair<int,int>
#define F first
#define S second
using namespace std;

Mine g(int x) { return { pow(10, x - 1), pow(10, x) - 1 }; }

void solve() {
    int A, B, C, k; cin >> A >> B >> C >> k;
    Mine a = g(A), b = g(B), c = g(C);
    Mine rg = { a.F + b.F, a.S + b.S };
    if (c.S < rg.F || rg.S < a.F) { cout << -1 << endl; return; }
    if (c.F < rg.F) {
        int end = min(c.S, rg.S);
        int amin = end - b.S;
        if (a.F <= amin) {

        }
        else {

        }
    }



}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}