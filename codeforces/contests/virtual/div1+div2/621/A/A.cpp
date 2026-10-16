#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < a[i] && d >= i; j++) {
            a[0]++;
            d -= i;
        }
    }
    cout << a[0] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}