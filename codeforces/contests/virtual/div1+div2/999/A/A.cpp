#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int e = 0;
    int o = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        x & 1 ? o++ : e++;
    }
    cout << (e ? o + 1 : max(o - 1, 0)) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}