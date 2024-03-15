#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    map<int, int> h;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        h[a]++;
        if (h[a] >= 3)ans = a;
    }
    cout << ((ans) ? ans : -1) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}