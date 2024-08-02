#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(2 * n);
    for (auto& c : a) cin >> c;
    sort(a.begin(), a.end());
    int i = 0, j = n;
    for (int k = 0; k < n; k++) {
        cout << a[i++] << " " << a[j++] << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}