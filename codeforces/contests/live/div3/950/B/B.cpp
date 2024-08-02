#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, f, k;
    cin >> n >> f >> k;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    int val = a[f - 1];
    sort(a.rbegin(), a.rend());
    if (k == n || a[k] < val) {
        cout << "YES";
    }
    else {
        cout << (a[k - 1] == a[k] && a[k] == val ? "MAYBE" : "NO");
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
