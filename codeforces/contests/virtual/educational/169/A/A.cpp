#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    if (n > 2) {
        cout << "NO";
    }
    else {
        sort(a.begin(), a.end());
        cout << (a[0] + 1 == a[1] ? "NO" : "YES");
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
