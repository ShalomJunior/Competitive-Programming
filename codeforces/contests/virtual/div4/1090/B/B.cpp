#include <bits/stdc++.h>
using namespace std;

const int N = 7;
const int INF = 1e9;

void solve() {
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        a[i] *= -1;
    }
    int s = accumulate(a.begin(), a.end(), 0);
    int ans = -INF;
    for (int i = 0; i < N; i++) {
        ans = max(ans, s - 2 * a[i]);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}