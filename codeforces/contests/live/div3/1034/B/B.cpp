#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, j, k;
    cin >> n >> j >> k;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    if (k >= 2) {
        cout << "YES";
    }
    else {
        int mx = *max_element(a.begin(), a.end());
        cout << (a[j - 1] == mx ? "YES" : "NO");
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
