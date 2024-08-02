#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    int g = 0;
    int mx = 0;
    for (auto& c : a) {
        g = __gcd(g, c);
        mx = max(mx, c);
    }
    int cnt = n - mx / g;
    cout << (cnt & 1 ? "Alice" : "Bob") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
