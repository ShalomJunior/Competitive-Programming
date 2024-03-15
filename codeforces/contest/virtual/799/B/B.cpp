#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    set<int> s;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        if (s.count(a))ans++;
        else s.insert(a);
    }
    if (ans & 1)ans++;
    cout << n - ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}