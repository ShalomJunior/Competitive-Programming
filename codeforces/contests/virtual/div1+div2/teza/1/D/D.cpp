#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    int x = n / (m + 1);
    int y = n / k;
    int z = min(x, y);
    vector<int> p(z);
    iota(p.begin(), p.end(), 0);
    for (int i = 0; i < n; i++) {
        cout << p[i % z] << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}