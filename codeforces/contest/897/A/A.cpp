#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    vector<int> b(n);
    b[0] = (a[0] == 1 ? 2 : 1);
    for (int i = 1; i < n; i++) {
        b[i] = b[i - 1] + 1;
        if (b[i] == a[i]) b[i]++;
    }
    cout << b[n - 1] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
