#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int w = 0;
    int h = 0;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        w = max(w, x);
        h = max(h, y);
    }
    cout << (w + h) * 2 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}