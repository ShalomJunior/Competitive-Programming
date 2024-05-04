#include <bits/stdc++.h>
using namespace std;

const int N = 9;
void solve() {
    vector<string> a(N);
    for (auto& c : a) cin >> c;
    for (int i = 0; i < N; i++) {
        int j = (i % 3) * 3 + i / 3;
        int k = (j + 1) % 3;
        a[i][j] = a[i][k];
    }
    for (auto& c : a) cout << c << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}