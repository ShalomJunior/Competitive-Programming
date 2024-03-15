#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    sort(a.begin(), a.end());
    if (a[0] == a[n - 1]) {
        cout << -1 << endl;
    }
    else {
        int i = lower_bound(a.begin(), a.end(), a[n - 1]) - a.begin();
        cout << i << " " << n - i << endl;
        for (int j = 0; j < n; j++) {
            cout << a[j] << (j == i - 1 ? '\n' : ' ');
        }
        cout << endl;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}