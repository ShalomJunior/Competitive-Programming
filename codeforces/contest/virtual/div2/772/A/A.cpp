#include <bits/stdc++.h>
using namespace std;

const int N = 31;
void solve() {
    int n; cin >> n;
    vector<int> a(N);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        for (int j = 0; j < N; j++) {
            if (x & (1 << j)) a[j] = 1;
        }
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        ans += a[i] * (1 << i);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}