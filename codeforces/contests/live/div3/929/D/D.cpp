#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    map<int, int> h;
    for (auto& c : a) {
        cin >> c;
        h[c]++;
    }
    sort(a.begin(), a.end());
    if (h[a[0]] == 1) {
        cout << "YES" << endl;
        return;
    }
    if ((a[0] == a.back()) || (a[0] == a[1] && a[0] == 1)) {
        cout << "NO" << endl;
        return;
    }
    int g = a[0];
    for (auto& c : a) g = __gcd(g, c);
    cout << (g == a[0] ? "NO" : "YES") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
